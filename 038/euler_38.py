#!/usr/bin/env python

def is_pandigital(s):
    return len(s) == 9 and all(s.count(c) == 1 for c in '123456789')


if __name__ == '__main__':
    from itertools import product
    combs = [
        (1, 9), (1, 8), (1, 7), (1, 6), (1, 5),
        (2, 3), (2, 4),
        (3, 3),
        (4, 2)
    ]

    pandigital = set()
    digits = (1, 2, 3, 4, 5, 6, 7, 8, 9)
    for outer, inner in combs:
        nums = (i for i in range(10 ** (outer - 1), 10 ** outer))
        mult = (digits[i:(i + inner)] for i in range(10 - inner))
        pandigital.update(list(filter(
            is_pandigital,
            (''.join(map(
                str,
                (num * m for m in mul))) for num, mul in product(nums, mult)
            )
        )))
    print(max(pandigital))
    print(pandigital)
