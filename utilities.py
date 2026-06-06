"""Various utility functions for use in the proton script"""

import io
import sys
import os
from argparse import Namespace
from pathlib import Path

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


def primary_gpu_supports_vulkan(major: int, minor: int, patch: int = 0, /, device_filter: str = '') -> bool:
    from vulkan import (VulkanError, VulkanInstance, VkPhysicalDeviceType, VulkanPhysicalDeviceAllFeatures, VulkanExtensionProperties, VulkanPhysicalDeviceProperties)

    discrete_gpus: list[
        tuple[VulkanPhysicalDeviceProperties, list[VulkanExtensionProperties], VulkanPhysicalDeviceAllFeatures]] = []
    integrated_gpus: list[
        tuple[VulkanPhysicalDeviceProperties, list[VulkanExtensionProperties], VulkanPhysicalDeviceAllFeatures]] = []
    virtual_gpus: list[
        tuple[VulkanPhysicalDeviceProperties, list[VulkanExtensionProperties], VulkanPhysicalDeviceAllFeatures]] = []

    try:
        with VulkanInstance() as instance:
            for device in instance.enumerate_physical_devices():
                properties, idproperties = device.get_properties()

                if device_filter:
                    device_uuid = ''.join(f'{n:x}' for n in idproperties.deviceUUID)
                    if device_filter != device_uuid and device_filter not in properties.deviceName:
                        continue

                features = device.get_features()
                extensions = device.get_extensions()

                match properties.deviceType:
                    case VkPhysicalDeviceType.DISCRETE_GPU:
                        discrete_gpus.append((properties, extensions, features))
                    case VkPhysicalDeviceType.INTEGRATED_GPU:
                        integrated_gpus.append((properties, extensions, features))
                    case VkPhysicalDeviceType.VIRTUAL_GPU:
                        virtual_gpus.append((properties, extensions, features))

            # this handles the case that the device filter is malformed and doesn't match any GPUs.
            # Instead of a silent fallback to sarek, let it break later on with upstream dxvk
            if not discrete_gpus and not integrated_gpus and not virtual_gpus:
                raise VulkanError

    except VulkanError:
        return True

    gpus_to_look_at = discrete_gpus or integrated_gpus or virtual_gpus
    return any(
        _props.apiVersion >= (major, minor, patch) and all((
            # features
            _feats.features12.descriptorIndexing,
        )) and all((
            # extensions
        ))
        for _props, _extens, _feats in gpus_to_look_at
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

    pass


__all__ = [
    'log_environment',
    'primary_gpu_supports_vulkan',
]
