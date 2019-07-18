def euclide(a, b):
    r = a % b
    while r != 0:
        a = b
        b = r
        r = a % b
    print(b)
    return b


euclide(140, 70)
