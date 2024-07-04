from parallel_sparse_tools.matvec._matvec_impl import (
    csr_matvec,
    csc_matvec,
    ReturnState,
)
import numpy as np
import scipy.sparse as sp
import pytest


def setup_benchmark(N):

    nnz = int(N * np.log(N))
    ids = np.random.choice(0, N**2, size=nnz, replace=False)
    row = ids % N
    col = ids // N
    data = np.random.randint(-16, 16, size=nnz).astype(np.int8)

    A = sp.csr_matrix((data, (row, col)), shape=(N, N))
    alpha = np.array(1.0j, dtype=np.complex128)
    x = np.random.uniform(-1, 1, size=N).astype(np.complex128)
    result_type = np.result_type(alpha, x, A.dtype)
    y = np.zeros(N, dtype=result_type)
    x = x.astype(result_type)

    return A, alpha, x, y


def apply_csr(A, alpha, x, y):
    status = csr_matvec(
        True, A.shape[0], A.shape[1], alpha, A.indptr, A.indices, A.data, x, y
    )
    assert status == ReturnState.SUCCESS


def apply_csc(A, alpha, x, y):
    A = A.T
    status = csc_matvec(
        True, A.shape[0], A.shape[1], alpha, A.indptr, A.indices, A.data, x, y
    )
    assert status == ReturnState.SUCCESS


@pytest.mark.parametrize("size", [100, 1000, 10000, 100000])
def test_csr(benchmark, size):

    args = setup_benchmark(size)
    benchmark(apply_csr, *args)


@pytest.mark.parametrize("size", [100, 1000, 10000, 100000])
def test_csc(benchmark, size):

    args = setup_benchmark(size)
    benchmark(apply_csc, *args)
