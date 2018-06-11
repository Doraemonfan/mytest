
def hanoi(n, a='a', b='b', c='c'):
    if n == 1:
        print(a, '->', b)
    else:
        hanoi(n-1, a, c, b)
        print(a, '->', b)
        hanoi(n-1, c, b, a)

hanoi(3)
print()
hanoi(4)
