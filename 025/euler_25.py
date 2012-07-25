#!/usr/bin/env python

from itertools import dropwhile

n = 1 # Really nasty hack, i figured too lately, that the index is needed...

def fib_gen():
	global n
	a = 1
	b = 0
	while True:
		yield a
		n += 1
		a, b = a+b, a

result = next(dropwhile(lambda x: len(str(x))<1000, fib_gen()))

print(n)
