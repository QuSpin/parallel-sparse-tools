from setuptools import find_packages, setup, Extension
from Cython.Build import cythonize
from typing import List
import os
import sys
import glob
import subprocess
import numpy as np


def extra_compile_args() -> List[str]:
    if sys.platform in ["win32", "cygwin", "win64"]:
        extra_compile_args = ["/openmp"]
    if sys.platform in ["darwin"]:
        extra_compile_args = [
            "-DLLVM_ENABLE_PROJECTS",
            "-Xpreprocessor",
            "-fopenmp-version=50"
            "-fopenmp",
        ]
    else:
        extra_compile_args = ["-fopenmp"]

    return extra_compile_args


def extra_link_args() -> List[str]:
    if sys.platform in ["win32", "cygwin", "win64"]:
        extra_link_args = ["/openmp"]
    if sys.platform in ["darwin"]:
        extra_link_args = [
            "-DLLVM_ENABLE_PROJECTS",
            "-Xpreprocessor",
            "-fopenmp-version=50"
            "-fopenmp",
        ]
    else:
        extra_link_args = ["-fopenmp"]

    return extra_link_args


def matvec_extension() -> List[Extension]:
    package_path = ("parallel_sparse_tools", "matvec")
    package_dir = os.path.join("src", *package_path)

    subprocess.check_call(
        [sys.executable, os.path.join(package_dir, "generate_oputils.py")]
    )

    includes = [
        np.get_include(),
        os.path.join("src", "parallel_sparse_tools", "matvec", "_oputils"),
    ]

    return generate_extensions(package_path, includes)


def expm_multiply_parallel_core_extension() -> List[Extension]:
    package_path = ("parallel_sparse_tools", "expm_multiply_parallel_core")
    package_dir = os.path.join("src", *package_path)

    subprocess.check_call(
        [sys.executable, os.path.join(package_dir, "generate_source.py")]
    )

    includes = [
        np.get_include(),
        os.path.join("src", "parallel_sparse_tools", "matvec", "_oputils"),
        os.path.join(package_dir, "source"),
    ]

    return generate_extensions(package_path, includes)


def generate_extensions(package_path, includes=[]):
    package_dir = os.path.join("src", *package_path)
    cython_src = glob.glob(os.path.join(package_dir, "*.pyx"))

    exts = []

    for cython_file in cython_src:
        module_name = os.path.split(cython_file)[-1].replace(".pyx", "")
        module_path = ".".join(package_path + (module_name,))

        exts.append(
            Extension(
                module_path,
                [cython_file],
                include_dirs=includes,
                extra_compile_args=extra_compile_args(),
                extra_link_args=extra_link_args(),
            )
        )

    return cythonize(exts, include_path=includes)


ext_modules = [
    *matvec_extension(),
    *expm_multiply_parallel_core_extension(),
]
setup(
    include_package_data=True,
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    ext_modules=ext_modules,
)
