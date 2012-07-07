#!/usr/bin/env python

import itertools as it

def fib():
	a = 1
	b = 0
	while True:
		yield a
		a, b = a+b, a

result = sum(filter(lambda y: y%2==0, it.takewhile(lambda x: x<=4e6, fib())))
print(result)
