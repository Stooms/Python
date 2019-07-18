import numpy as np


def carre_magique(n):
    m = np.zeros((n, n))
    i = n-1
    j = int((n-1)/2)
    m[i][j] = 1
    compteur = n*n - 1
    while compteur != 0:
        if m[(i+1) % 5][(j+1) % 5] == 0:
            m[(i+1) % 5][(j+1) % 5] = m[i % 5][j % 5] +1
            i = (i+1) % 5
            j = (j+1) % 5
        else:
            m[(i-1) % 5][j % 5] = m[i % 5][j % 5]+1
            i = (i-1) % 5
        compteur -= 1
    print(m)


carre_magique(5)