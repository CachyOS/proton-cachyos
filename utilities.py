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
        'MANGOHUD',
        'PROTON_DLSS_UPGRADE',
        'PROTON_XESS_UPGRADE',
        'PROTON_FSR3_UPGRADE',
        'PROTON_FSR4_UPGRADE',
        'PROTON_FSR4_RDNA3_UPGRADE',
        'DXVK_FILTER_DEVICE_NAME',
        'PROTON_DISCORD_BRIDGE',
    ) if name in env):
        log_file.write(var + ": " + env[var] + "\n")


if __name__ == '__main__':
    pass


__all__ = ['log_environment']
