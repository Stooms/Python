# def reverse_my_string(a, b):
#     for char in b:
#         a.insert(1, char)
#
#
# a = ['a']
#
# b = 'Hello'
#
# c = reverse_my_string(a, b)
#
# print(a)
#
# print(b[::-1])
#
# print(c)
#


def proche_zero(l):
    proche = l.pop(0)
    print(proche, l)
    for num in l:
        if proche == 0:
            print("youpi")
            break
        elif abs(proche) > abs(num):
            proche = num
        elif abs(proche) == abs(num) and proche != num:
            proche = min(proche, num)
    print(proche)
    return proche


proche_zero([-4, 4, 12, 0])
