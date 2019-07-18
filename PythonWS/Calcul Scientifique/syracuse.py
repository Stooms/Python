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