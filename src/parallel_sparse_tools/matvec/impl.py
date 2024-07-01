from numbers import Number
from typing import NoReturn, Optional
from parallel_sparse_tools.matvec._ext import (
    ReturnState,
    csr_matvec,
    csc_matvec,
    dia_matvec,
)
from collections import namedtuple
import numpy as np
import scipy.sparse as sp

DENSE_DTYPES = [np.float32, np.float64, np.complex64, np.complex128]
DATA_DTYPES = [np.int8, np.int16, np.float32, np.float64, np.complex64, np.complex128]
INDEX_DTYPES = [np.int32, np.int64]


def process_error(status: ReturnState, **args) -> NoReturn:
    NamedArgs = namedtuple("NamedArgs", args.keys())

    args = NamedArgs(**args)
    if status is ReturnState.INVALID_DENSE_TYPE:
        raise ValueError("Invalid dense type")
    elif status is ReturnState.INVALID_INDEX_TYPE:
        raise ValueError("Invalid index type")
    elif status is ReturnState.INVALID_N_ROW:
        raise ValueError(f"Invalid number of rows, must be >= 0, but got {args.n_row}")
    elif status is ReturnState.INVALID_N_COL:
        raise ValueError(
            f"Invalid number of columns, must be >= 0, but got {args.n_col}"
        )
    elif status is ReturnState.MISMATCH_IN_OUT_TYPES:
        raise ValueError(
            f"Mismatched input and output types, found "
            f"{args.input.dtype} and {args.output.dtype}"
        )
    elif status is ReturnState.MISMATCH_INDEX_TYPES:
        raise ValueError(
            f"Mismatched dtype between indices and indptr, found "
            f"{args.indices.dtype} and {args.indptr.dtype}, respectively"
        )
    elif status is ReturnState.INVALID_OUT_TYPE:
        raise ValueError(f"Invalid output type {args.output.dtype}")
    elif status is ReturnState.INVALID_OUT_NDIM:
        raise ValueError(
            f"Expecting output ndim to be 1 or 2, found {args.output.ndim}."
        )
    elif status is ReturnState.MISMATCH_OUT_DIM:
        raise ValueError(
            f"Expecting output rows {args.n_row}, found {args.output.shape[1]}."
        )
    elif status is ReturnState.INVALID_IN_TYPE:
        raise ValueError(
            f"Invalid input type {args.input.dtype}, expecting: {DENSE_DTYPES}"
        )
    elif status is ReturnState.INVALID_IN_NDIM:
        raise ValueError(f"Expecting input ndim to be 1 or 2, found {args.input.ndim}.")
    elif status is ReturnState.MISMATCH_IN_DIM:
        raise ValueError(
            f"Expecting input rows {args.n_col}, found {args.input.shape[0]}."
        )
    else:
        raise RuntimeError(f"Unknown error {status}")


def _cast_scalar(a: Number) -> np.ndarray:
    return np.array(a, dtype=np.result_type(np.min_scalar_type(a), np.float32))


def matvec(
    A: sp.sparray,
    py_input: np.ndarray,
    py_output: Optional[np.ndarray] = None,
    a: Number = 1.0,
    overwrite_output: bool = True,
):
    if not isinstance(A, sp.spmatrix):
        raise ValueError("A must be a scipy.sparse.spmatrix")

    a = _cast_scalar(a)

    if py_output is None:
        py_output = np.zeros_like(input).astype(np.result_type(A.data, py_input, a))

    py_input = py_input.astype(py_output.dtype, copy=False)

    if A.format == "csr":
        status = csr_matvec(
            overwrite_output,
            A.shape[0],
            A.shape[1],
            a,
            A.indptr,
            A.indices,
            A.data,
            py_input,
            py_output,
        )
    elif A.format == "csc":
        status = csc_matvec(
            overwrite_output,
            A.shape[0],
            A.shape[1],
            a,
            A.indptr,
            A.indices,
            A.data,
            py_input,
            py_output,
        )
    elif A.format == "dia":
        status = dia_matvec(
            overwrite_output,
            A.shape[0],
            A.shape[1],
            a,
            A.offsets,
            A.data,
            py_input,
            py_output,
        )
    else:
        raise ValueError(f"No matvec found for format {A.format}")

    if status != ReturnState.SUCCESS:
        process_error(status, A=A, input=py_input, output=py_output, a=a)

    return py_output
