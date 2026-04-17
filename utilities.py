"""Various utility functions for use in the proton script"""

import sys
from argparse import Namespace
from pathlib import Path


class Config(Namespace):
    class Path(Namespace):
        cache_dir: Path = Path.home().joinpath('.cache', 'protonfixes')

    path = Path()


config = Config()


class Log:
    @staticmethod
    def warn(msg):
        print('[Utilities] WARN: ' + msg, file=sys.stderr)

    @staticmethod
    def info(msg):
        print('[Utilities] INFO: ' + msg, file=sys.stderr)

    @staticmethod
    def crit(msg):
        print('[Utilities] ERROR: ' + msg, file=sys.stderr)


log = Log()

if __name__ == "__main__":
    pass
