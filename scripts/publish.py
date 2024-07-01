import tomlkit
from packaging.version import Version
import os
import argparse
import git


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


def exec_udpate(repo, args):
    version = Version(args.version)

    write_version(version)

    if not args.dry_run:
        raise NotImplementedError("Publishing is not implemented yet")


def get_branch(repo):
    output = repo.git.branch()
    for branch in output.split("\n"):
        if branch.startswith("*"):
            return branch[2:]

    raise ValueError("No branch found")


def main():
    repo = git.Repo()
    branch = get_branch(repo)

    try:
        repo.git.stash()
        if branch != "main":
            repo.git.checkout("main")
            repo.git.pull()

        args = parser.parse_args()

        exec_udpate(repo, args)
    finally:
        if branch != "main":
            repo.git.checkout(branch, force=True)

        repo.git.stash("pop")


if __name__ == "__main__":
    main()
