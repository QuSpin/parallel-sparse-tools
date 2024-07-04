from typing import Literal
import tomlkit
from packaging.version import Version
import os
import argparse
import git


class Executor:
    def __init__(self, repo):
        self.repo = repo
        self._pyproject = None

    @property
    def pyproject(self):
        if self._pyproject is None:
            with open("pyproject.toml", "r") as f:
                self._pyproject = tomlkit.load(f)

        return self._pyproject

    def get_version(self) -> Version:
        self.og_version = self.pyproject["project"]["version"]

        return self.og_version

    def bump_patch(self) -> None:
        assert not self._updated, "Version already updated"
        self._updated = True

        major, minor, patch = self.get_version().release
        self.pyproject["project"]["version"] = f"{major}.{minor}.{patch + 1}"

    def bump_minor(self) -> None:
        assert not self._updated, "Version already updated"
        self._updated = True

        major, minor, patch = self.get_version().release
        self.pyproject["project"]["version"] = f"{major}.{minor + 1}.{patch}"

    def bump_major(self) -> None:
        assert not self._updated, "Version already updated"
        self._updated = True

        major, minor, patch = self.get_version().release
        self.pyproject["project"]["version"] = f"{major + 1}.{minor}.{patch}"

    def write_version_info(self) -> None:
        assert self._is_context, "Version not updated"

        version = self.pyproject["project"]["version"]

        with open(
            os.path.join("src", "parallel_sparse_tools", "_version.py"), "w"
        ) as f:
            f.write(f'__version__ = "{version}"\n')

        with open("pyproject.toml", "w") as f:
            f.write(self.pyproject.as_string())

        self._written = True
        self.commit()

    def commit(self) -> None:
        assert self._written, "Version not updated"
        self.repo.git.add("pyproject.toml")
        self.repo.git.add("src/parallel_sparse_tools/_version.py")
        self.repo.git.commit("-m", f"Release {self.pyproject['project']['version']}")

        self._committed = True
        self.tag()

    def tag(self) -> None:
        assert self._committed, "Version not committed"
        self._tagged = True
        version = self.pyproject["project"]["version"]
        self.repo.create_tag(f"v{version}")

        self.push()

    def push(self) -> None:
        assert self._tagged, "Tag not created"
        self.repo.git.push()
        self.repo.git.push("--tags")

    def run_updates(self, number: Literal["patch", "minor", "major"]) -> None:
        if number == "patch":
            self.bump_patch()
        elif number == "minor":
            self.bump_minor()
        elif number == "major":
            self.bump_major()
        else:
            raise ValueError(f"Invalid option: {number}")

        new_version = self.pyproject["project"]["version"]
        response = input(
            f"Ready to release {self.og_version} -> {new_version}. Press enter (y) to continue..."
        )

        if response.lower() != "y":
            print("Aborting")
            return

        self.write_version_info()

    def get_branch(self) -> str:
        output = self.repo.git.branch()
        for branch in output.split("\n"):
            if branch.startswith("*"):
                return branch[2:]

        raise ValueError("No branch found")

    def __enter__(self) -> "Executor":
        self._is_context = True
        self._written = False
        self._committed = False
        self._tagged = False
        self._orginal_branch = self.get_branch()

        try:
            self.repo.git.stash()
            if self._orginal_branch != "main":
                self.repo.git.checkout("main")
                self.repo.git.pull()

            return self
        finally:
            if self._orginal_branch != "main":
                self.repo.git.checkout(self._orginal_branch, force=True)

            self.repo.git.stash("pop")

    def __exit__(self, exc_type, exc_value, traceback):
        pass


parser = argparse.ArgumentParser(
    prog="Publshing script", description="This script is used to publish the package"
)

parser.add_argument(
    "number",
    type=str,
    choices=["patch", "minor", "major"],
    help="The number to bump, either 'patch', 'minor' or 'major'",
)


def main():
    repo = git.Repo()

    args = parser.parse_args()

    with Executor(repo) as executor:
        executor.run_updates(args.number)


if __name__ == "__main__":
    main()
