#!/usr/bin/env python

from itertools import chain, starmap


def is_pandigital(s):
    return len(s) == 9 and all(s.count(c) == 1 for c in '123456789')


def rangeproduct(a, b):
    return (
        ''.join(
            map(
                str,
                (_r * d for d in range(1, b + 1))
            )
        ) for _r in range(10 ** (a - 1), 10 ** a)
    )


combs = [
    (1, 9), (1, 8), (1, 7), (1, 6), (1, 5),
    (2, 3), (2, 4),
    (3, 3),
    (4, 2)
]

result = max(
    filter(
        is_pandigital,
        chain(*starmap(rangeproduct, combs))
    )
)
print(result)
