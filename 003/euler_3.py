#!/usr/bin/env python

def gen_primes():
	"""Stolen from stackoverflow; beautiful sieve of Erastosthenes."""
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

def primefactors(x):
	g = gen_primes()
	p = g.next()
	factors = set()
	while x > 1:
		if x%p == 0:
			factors.add(p)
			x /= p
		else:
			p = g.next()
	return factors

assert primefactors(13195) == set([5, 7, 13, 29])
print(max(primefactors(600851475143)))
