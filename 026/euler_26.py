#!/usr/bin/env python

def longest_recurrance_in_one_over(x):
    rest = 1
    rests = []
    while rest != 0:
        rest *= 10
        n = rest // x
        rest -= n * x
        if rest in rests:
            return len(rests[rests.index(rest):])
        rests.append(rest)
    return 0


reccs = list(map(longest_recurrance_in_one_over, range(1, 1000)))
print(reccs.index(max(reccs)) + 1)
