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
        'DXVK_FILTER_DEVICE_NAME',
        'DXVK_FILTER_DEVICE_UUID',
        '__NV_PRIME_RENDER_OFFLOAD',
        '__VK_LAYER_NV_optimus',
        '__GLX_VENDOR_LIBRARY_NAME',
        'DXVK_CONFIG',
        'VKD3D_CONFIG',
        'MANGOHUD',
        'PROTON_DISCORD_BRIDGE',
        'PROTON_DLSS_UPGRADE',
        'PROTON_XESS_UPGRADE',
        'PROTON_FSR3_UPGRADE',
        'PROTON_FSR4_UPGRADE',
        'PROTON_FSR4_RDNA3_UPGRADE',
        'PROTON_FFX3_UPGRADE',
        'PROTON_FFX4_UPGRADE',
        'PROTON_MLFG_UPGRADE',
        'PROTON_LOCAL_SHADER_CACHE',
        'WINE_CANONICAL_HOLE',
    ) if name in env):
        log_file.write(var + ": " + env[var] + "\n")


if __name__ == '__main__':
    pass


__all__ = ['log_environment']
