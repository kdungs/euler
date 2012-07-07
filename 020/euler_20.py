#!/usr/bin/env python

import operator as op

factorial = lambda n: reduce(op.mul, xrange(1, n+1))
sum_digits = lambda x: sum(int(a) for a in str(x))

print(sum_digits(factorial(100)))

"""
Found out later that one could have easily used the factorial method from the math package...
"""
