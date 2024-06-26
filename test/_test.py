from parallel_sparse_tools.matvec._oputils import csr_matvec
import numpy as np
import scipy.sparse as sp
from cProfile import Profile

N = 10000
A = sp.rand(N, N, density=np.log(N)/N, format='csr').astype(np.float64)
x = np.random.uniform(-1, 1, size=N).astype(np.float64)
y = np.zeros(N).astype(np.float64)


with Profile() as pr:
    for i in range(100):
        status = csr_matvec(True, A.shape[0], A.shape[1], np.array(1.0j), A.indptr, A.indices, A.data, x, y)

pr.print_stats("cumtime")

with Profile() as pr:
    for i in range(100):
        y = 1.0j * (A @ x)

pr.print_stats("cumtime")
