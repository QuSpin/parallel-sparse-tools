# Available at setup time due to pyproject.toml
from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup
import numpy as np
import os
import sys
from typing import List
import tomllib


with open("pyproject.toml", "rb") as f:
    pyproject = tomllib.load(f)


if os.environ.get("COVERAGE", False) and sys.platform in [
    "win32",
    "cygwin",
    "win64",
    "darwin",
]:
    raise ValueError("Coverage is not supported on Windows or macOS")


def extra_compile_args() -> List[str]:
    if sys.platform in ["win32", "cygwin", "win64"]:
        extra_compile_args = ["/openmp"]
    elif sys.platform in ["darwin"]:
        extra_compile_args = [
            "-mmacosx-version-min=10.15",
            "-fopenmp",
        ]
    else:
        extra_compile_args = ["-fopenmp"]

    if os.environ.get("COVERAGE", False):
        extra_compile_args += [
            "--coverage",
            "-fno-inline",
            "-fno-inline-small-functions",
            "-fno-default-inline",
            "-O0",
        ]

    return extra_compile_args


def extra_link_args() -> List[str]:
    if sys.platform in ["win32", "cygwin", "win64"]:
        extra_link_args = ["/openmp"]
    if sys.platform in ["darwin"]:
        extra_link_args = [
            "-fopenmp",
        ]
    else:
        extra_link_args = ["-fopenmp"]

    if os.environ.get("COVERAGE", False):

        extra_link_args += ["--coverage"]

    return extra_link_args


ext_modules = [
    Pybind11Extension(
        "parallel_sparse_tools.matvec._matvec_impl",
        sources=[
            os.path.join("src", "parallel_sparse_tools", "matvec", "_matvec_impl.cxx")
        ],
        define_macros=[
            ("VERSION_INFO", pyproject["project"]["version"]),
        ],
        include_dirs=[
            os.path.join("src", "parallel_sparse_tools", "matvec", "include"),
            np.get_include(),
        ],
        extra_compile_args=extra_compile_args(),
        extra_link_args=extra_link_args(),
    ),
]

setup(
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
