#!/usr/bin/env python

import itertools as it

def gen_primes():
	"Stolen from stackoverflow; beautiful sieve of Erastosthenes."
	D = {}
	q = 2
	while True:
		if q not in D:
			yield q
			D[q * q] = [q]
		else:
			for p in D[q]:
				D.setdefault(p + q, []).append(p)
			del D[q]
		q += 1

r = sum(it.takewhile(lambda x: x < 2e6, gen_primes()))
print(r)
