from parallel_sparse_tools.expm_multiply_parallel_core.expm_multiply_parallel_core import ExpmMultiplyParallel
import numpy as np
import scipy.sparse as sp
import scipy.linalg as la

np.random.seed(0)
N = 100

density = np.log(N) / N

H = sp.random(N, N, density=density) + 1j * sp.random(N, N, density=density)
# H = H + H.T.conj()
# H = np.diag(np.random.rand(N))



a = 0.01j

U = ExpmMultiplyParallel(H, a = a)

v = np.random.uniform(size=(N, 2))

Uv = U.dot(v)

e,V = la.eigh(H.toarray())

U_exact_v = V @ ((np.exp(e*a)* V.conj()).T @ v)

print((np.log(Uv)/a).real)
print((np.log(U_exact_v)/a).real)



assert np.linalg.norm(Uv - U_exact_v) < 1e-10, f"\n{Uv=}\n{U_exact_v=}"

