#!/usr/bin/env python

from fractions import Fraction
from functools import reduce
from operator import mul


result = []
for b in range(1, 10):
    for a in range(1, b):
        frac = a / b
        for c in range(1, 10):
            _1 = (a * 10 + c) / (b * 10 + c)
            _2 = (a * 10 + c) / (b + 10 * c)
            _3 = (a + 10 * c) / (b * 10 + c)
            _4 = (a + 10 * c) / (b + 10 * c)
            if frac == _1 or frac == _2 or frac == _3 or frac == _4:
                result.append(Fraction(a, b))


print(reduce(mul, result))
