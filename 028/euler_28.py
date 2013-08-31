#!/usr/bin/env python

def diagonals(N=1001):
    value = 1
    yield value
    for n in range(2, N, 2):
        for _ in range(4):
            value += n
            yield value


print(sum(diagonals()))
