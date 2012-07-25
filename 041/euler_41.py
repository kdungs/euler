#!/usr/bin/env python

from sympy import isprime
from itertools import permutations

digits = "987654321"

def solve():
	for i in range(len(digits)):
		for p in permutations(digits[i:]):
			x = int(''.join(p))
			if isprime(x):
				return x
	return -1

print(solve())
