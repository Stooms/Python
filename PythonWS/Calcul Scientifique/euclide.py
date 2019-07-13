import numpy as np


# def carre_magique(n):
#     m = np.zeros((n, n))
#     i = n-1
#     j = int((n-1)/2)
#     m[i][j] = 1
#     compteur = n*n - 1
#     while compteur != 0:
#         if m[(i+1) % 5][(j+1) % 5] == 0:
#             m[(i+1) % 5][(j+1) % 5] = m[i % 5][j % 5] +1
#             i = (i+1) % 5
#             j = (j+1) % 5
#         else:
#             m[(i-1) % 5][j % 5] = m[i % 5][j % 5]+1
#             i = (i-1) % 5
#         compteur -= 1
#     print(m)
#
#
# carre_magique(5)


def suite_syracuse(n):
    u=[n]
    k=0
    a=0
    while u[k] != 1:
        if u[k] % 2 == 0:
            u.append(u[k] // 2)
        else:
            u.append(3*u[k] + 1)
        if u[0]<u[k+1]:
            a = a+1
        k += 1
    print(u, k, a)
    return u, k, a


suite_syracuse(15)