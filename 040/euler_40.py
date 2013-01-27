#!/usr/bin/env python

from collections import deque
from functools import reduce
from itertools import count, islice
from operator import mul


def gen_constant():
    buf = deque()
    for c in count(1):
        buf.extend(map(int, str(c)))
        yield buf.popleft()


# from itertools recipes
def nth(iterable, n, default=None):
    "Returns the nth item or a default value"
    return next(islice(iterable, n, None), default)


relevant_digits = [
    nth(gen_constant(), n-1)
    for n in [1, 10, 100, 1000, 10000, 100000, 1000000]
]
result = reduce(mul, relevant_digits)

print(relevant_digits)
print(result)
