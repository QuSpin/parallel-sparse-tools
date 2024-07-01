import tomlkit
from packaging.version import Version
import os
import argparse


def write_version(version: Version):
    with open(os.path.join("src", "parallel_sparse_tools", "_version.py"), "w") as f:
        f.write(f'__version__ = "{version}"\n')

    with open("pyproject.toml", "r") as f:
        pyproject = tomlkit.load(f)

    pyproject["project"]["version"] = str(version)

    with open("pyproject.toml", "w") as f:
        f.write(pyproject.as_string())


parser = argparse.ArgumentParser(
    prog="Publshing script", description="This script is used to publish the package"
)

parser.add_argument("version", type=str, help="The version to publish")
parser.add_argument(
    "--dry-run", action="store_true", help="Dry run the publishing process"
)


args = parser.parse_args()

version = Version(args.version)
write_version(version)
