"""Various utility functions for use in the proton script"""

import io
import sys
import os
import uuid
from argparse import Namespace
from collections import defaultdict
from dataclasses import dataclass
from functools import cache
from itertools import groupby
from pathlib import Path

from vulkan import (
    VulkanPhysicalDeviceFeatures,
    VulkanExtensionProperties,
    VkPhysicalDeviceType,
    VulkanError,
    VulkanInstance,
    VulkanVersion,
    VulkanPhysicalDevice,
    VkDriverId
)


base_config = Path(os.getenv('XDG_CONFIG_HOME', '~/.config')).expanduser()
base_cache = Path(os.getenv('XDG_CACHE_HOME', '~/.cache')).expanduser()


class Config(Namespace):
    class Path(Namespace):
        config_dir: Path = base_cache.joinpath('protonfixes')
        cache_dir: Path = base_cache.joinpath('protonfixes')

    path = Path()


class Log:
    @staticmethod
    def info(msg):
        sys.stderr.write('[Utilities] INFO: ' + msg)
        sys.stderr.flush()

    @staticmethod
    def warn(msg):
        sys.stderr.write('[Utilities] WARN: ' + msg)
        sys.stderr.flush()

    @staticmethod
    def crit(msg):
        sys.stderr.write('[Utilities] ERROR: ' + msg)
        sys.stderr.flush()


config = Config()
log = Log()


def log_environment(env: dict, log_file: io.TextIOWrapper):
    log_file.write('======================\n')
    log_file.write('Inherited environment\n')
    for var in (name for name in (
        'DISPLAY',
        '__NV_PRIME_RENDER_OFFLOAD',
        '__VK_LAYER_NV_optimus',
        '__GLX_VENDOR_LIBRARY_NAME',
    ) if name in env):
        log_file.write(var + ": " + env[var] + "\n")
    for var in sorted(name for name in env if name.startswith((
        "PROTON",
        "WINE",
        "DXVK",
        "VKD3D",
        "MANGOHUD"
    ))):
        log_file.write(var + ": " + env[var] + "\n")


@dataclass
class GPU:
    deviceType: VkPhysicalDeviceType
    deviceUUID: uuid.UUID
    deviceName: str
    vendorID: int
    driverID: VkDriverId
    driverName: str
    driverInfo: str
    apiVersion: VulkanVersion
    features: VulkanPhysicalDeviceFeatures
    extensions: list[VulkanExtensionProperties]

    @classmethod
    def from_physical_device(cls, device: VulkanPhysicalDevice):
        properties, driver_properties, id_properties = device.get_properties()
        features = device.get_features()
        extensions = device.get_extensions()
        return cls(
            properties.deviceType,
            id_properties.deviceUUID,
            properties.deviceName,
            properties.vendorID,
            driver_properties.driverID,
            driver_properties.driverName,
            driver_properties.driverInfo,
            properties.apiVersion,
            features,
            extensions
        )


@cache
def get_vulkan_gpus() -> list[GPU]:
    gpus: list[GPU] = []
    try:
        with VulkanInstance() as instance:
            for device in instance.enumerate_physical_devices():
                gpus.append(GPU.from_physical_device(device))
    except VulkanError:
        pass
    return gpus


def primary_gpu_supports_vulkan(
    major: int, minor: int, patch: int = 0, /,
    device_filter: str = '',
    device_features: list[str] | None = None,
    device_extensions: dict[str, int] | None = None
) -> bool:
    if device_features is None:
        device_features = []
    if device_extensions is None:
        device_extensions = {}

    gpus = get_vulkan_gpus()
    grouped: dict[VkPhysicalDeviceType, list[GPU]] = defaultdict(list)
    for group_type, gpus in groupby(gpus, lambda x: x.deviceType):
        grouped[group_type] = list(
            gpu
            for gpu in gpus
            if (
                not device_filter or
                device_filter in gpu.deviceName or
                device_filter in str(gpu.deviceUUID).replace('-', '')
            )
        )
    primary_category = (
            grouped[VkPhysicalDeviceType.DISCRETE_GPU] or
            grouped[VkPhysicalDeviceType.INTEGRATED_GPU] or
            grouped[VkPhysicalDeviceType.VIRTUAL_GPU]
    )

    if not primary_category:
        return True

    def supports_extension(gpu: GPU, name: str, version: int) -> bool:
        extension = next((
            e
            for e in gpu.extensions
            if e.extensionName == name
        ), None)
        if not extension:
            return False
        return extension.specVersion >= version

    return any(
        (gpu.apiVersion >= (major, minor, patch)) and
        (all(map(lambda feature: feature in gpu.features, device_features))) and
        (all(map(lambda requested_extension: supports_extension(gpu, *requested_extension), device_extensions.items())))
        for gpu in primary_category
    )


if __name__ == '__main__':
    print("\nDifferent versions")
    print(primary_gpu_supports_vulkan(1,2))
    print(primary_gpu_supports_vulkan(1,3))
    print(primary_gpu_supports_vulkan(1,4))
    print(primary_gpu_supports_vulkan(1,5))

    print("\nWith filter")
    print(primary_gpu_supports_vulkan(1,1, device_filter="744c6095a55e1f94172f15a2c18ea17a"))
    print(primary_gpu_supports_vulkan(1,1, device_filter="744c6095a55e1f94172f15a2c18ea17b"))
    print(primary_gpu_supports_vulkan(1,1, device_filter="NVIDIA"))
    print(primary_gpu_supports_vulkan(1,1, device_filter="AMD"))

    print("\nWith features")
    print(primary_gpu_supports_vulkan(1, 1, device_features=['descriptorIndexing']))

    print("\nDriver Info:")
    for gpu in get_vulkan_gpus():
        print(f'{gpu.deviceName=} {gpu.deviceUUID=} {gpu.driverID=} {gpu.driverName=} {gpu.driverInfo=}')

    pass


__all__ = [
    'get_vulkan_gpus',
    'log_environment',
    'primary_gpu_supports_vulkan',
]
