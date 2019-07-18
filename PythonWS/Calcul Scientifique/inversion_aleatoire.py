import numpy as np

def inversion(n):
    r = np.random.randn(n, n)
    m = np.dot(r, np.transpose(r))
    inverse_m = np.linalg.inv(m)
    print(np.allclose(np.dot(m, inverse_m), np.eye(n), rtol=1.0000e-5, atol=1.0000e-5))
    #print(np.dot(inverse_m, m))


inversion(3)