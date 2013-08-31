#!/usr/bin/env python

from functools import lru_cache
from math import sqrt


@lru_cache(maxsize=None)
def divisors(x):
    result = set([1])
    for d in range(int(sqrt(x)), 1, -1):
        if x % d == 0 and d not in result:
            result.add(d)
            _d = int(x / d)
            result.add(_d)
            _divs = divisors(_d)
            result.update(_divs)
            for a in _divs.difference(set([1])):
                result.add(int(x / a))
    return result


def abundant(x):
    return sum(divisors(x)) > x


def abundant_numbers(limit):
    if limit < 12:
        return None
    return set(filter(abundant, range(12, limit)))


def sums_of_two_abundant_numbers(limit):
    return set((x + y for x in abundant_numbers(limit) for y in abundant_numbers(limit) if x + y <= limit))


N = 28123 + 1
print(sum(set(range(1, N)).difference(sums_of_two_abundant_numbers(N))))
