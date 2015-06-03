#!/usr/bin/env python


def digitsum(x):
    return sum(map(int, str(x)))


max = 0
for a in range(0, 100):
    for b in range(0, 100):
        x = digitsum(a ** b)
        if x > max:
            max = x

print(max)
