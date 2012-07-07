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

def nth(iterable, n, default=None):
    "Returns the nth item or a default value"
    return next(it.islice(iterable, n-1, None), default)

assert nth(gen_primes(), 1) == 2
assert nth(gen_primes(), 2) == 3
assert nth(gen_primes(), 4) == 7
assert nth(gen_primes(), 6) == 13

r = nth(gen_primes(), 10001)
print(r)
