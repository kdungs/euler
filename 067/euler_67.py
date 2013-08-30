#!/usr/bin/env python

import numpy as np


def map_n(f, *args):
    return map(lambda arg: f(*arg), zip(*args))


def find_path(t):
    from functools import reduce
    return reduce(
        lambda lower, upper: np.array(list(map_n(
            max,
            upper + lower[:-1],
            upper + lower[1:]
        ))),
        reversed(t)
    )


if __name__ == '__main__':
    with open('triangle.txt') as f:
        triangle = list(map(
            lambda s: np.array(list(map(int, s.split(' ')))),
            f.readlines()
        ))
    print(find_path(triangle))
