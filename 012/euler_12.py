#!/usr/bin/env python

import math
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


def prime_split_number(x):
	primes = gen_primes()
	decomposition = []
	p = primes.next()

	while x > 1:
		if x%p == 0:
			decomposition.append(p)
			x /= p
		else:
			p = primes.next()

	d_dict = {'dividers': 2} # 1 and x
	for a in set(decomposition):
		d_dict[a] = 0
	for a in decomposition:
		d_dict[a] += 1
		d_dict['dividers'] += 1
	return d_dict

assert prime_split_number(10)['dividers'] == 4
assert prime_split_number(100)['dividers'] != 8
print prime_split_number(100)


def triangle_numbers():
	t = 0
	c = it.count(1)
	while True:
		t += c.next()
		yield t

def count_divisors(x):
	print x
	c = 2 # 1 and x
	i = 2
	while i <= x/2:
		if x%i == 0:
			c += 1
		i += 1
	return c

"""
result = it.dropwhile(
	lambda x: 500 >= count_divisors(x),
	it.dropwhile(
		lambda a: a < math.factorial(500),
		triangle_numbers()
	)
).next()
"""

"""print(result)"""
