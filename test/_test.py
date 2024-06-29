from parallel_sparse_tools.matvec._oputils import csr_matvec, ReturnState
import numpy as np
import scipy.sparse as sp
from cProfile import Profile

N = 1000000

nnz = int(N*np.log(N))
row = np.random.randint(0, N, size=nnz)
col = np.random.randint(0, N, size=nnz)
data = np.random.uniform(-1, 1, size=nnz)

A = sp.csr_matrix((data, (row, col)), shape=(N, N))
alpha = np.array(1.0j, dtype=np.complex128)
x = np.random.uniform(-1, 1, size=N).astype(np.complex128)
y = np.zeros(N).astype(np.result_type(alpha, x, A.dtype))

y_expected = alpha * (A @ x)
status = csr_matvec(True, A.shape[0], A.shape[1], alpha, A.indptr, A.indices, A.data, x, y)

assert status == ReturnState.SUCCESS
assert np.array_equal(y, y_expected)

with Profile() as pr:
    for i in range(10):
        status = csr_matvec(True, A.shape[0], A.shape[1], alpha, A.indptr, A.indices, A.data, x, y)
        assert status == ReturnState.SUCCESS

pr.print_stats("cumtime")

with Profile() as pr:
    for i in range(10):
        y = alpha * (A @ x)

pr.print_stats("cumtime")
