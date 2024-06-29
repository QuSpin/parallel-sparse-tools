from parallel_sparse_tools.matvec._matvec_impl import csr_matvec, ReturnState
import numpy as np
import scipy.sparse as sp
import pytest


def setup_benchmark(N):

    nnz = int(N * np.log(N))
    row = np.random.randint(0, N, size=nnz)
    col = np.random.randint(0, N, size=nnz)
    data = np.random.uniform(-1, 1, size=nnz)

    A = sp.csr_matrix((data, (row, col)), shape=(N, N))
    alpha = np.array(1.0j, dtype=np.complex128)
    x = np.random.uniform(-1, 1, size=N).astype(np.complex128)
    y = np.zeros(N).astype(np.result_type(alpha, x, A.dtype))

    return A, alpha, x, y


def apply_csr(A, alpha, x, y):
    status = csr_matvec(
        True, A.shape[0], A.shape[1], alpha, A.indptr, A.indices, A.data, x, y
    )
    assert status == ReturnState.SUCCESS


@pytest.mark.benchmark(
    group="csr-matvec",
)
def test_csr(benchmark):

    args = setup_benchmark(1000)
    benchmark(apply_csr, *args)
