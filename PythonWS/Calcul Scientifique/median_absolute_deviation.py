import numpy as np


def mad(x, axis=None):
    med = np.median(x, axis=axis, keepdims=True)
    mad = np.median(np.absolute(x - med), axis=axis)
    return mad


x = np.arange(4 * 5, dtype=float).reshape(4, 5)
print("x =\n", x)
print("MAD(x, axis=None)   =", mad(x))
print("MAD(x, axis=0)      =", mad(x, axis=0))
print("MAD(x, axis=1)      =", mad(x, axis=1))
print("MAD(x, axis=(0, 1)) =", mad(x, axis=(0, 1)))


