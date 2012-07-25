#!/usr/bin/env python

import itertools as it

N = 100000000

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

relevant_primes = list(it.islice(gen_primes(), N/2))

print(relevant_primes)
