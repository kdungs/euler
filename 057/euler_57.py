#!/usr/bin/env python

from fractions import Fraction

s = 1 + Fraction(1, 2)
counter = 0
for i in range(1000):
    s = 1 + Fraction(1, 1 + s)
    if len(str(s.numerator)) > len(str(s.denominator)):
        counter += 1

print(counter)
