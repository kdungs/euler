#!/usr/bin/env python

import itertools as it
import operator as op

# 364 since the longest word has 14 letters, 14*26 (assuming worst case -> all z)
TRIANGLE_NUMBERS = list(it.takewhile(lambda x: x<364, it.imap(lambda n: n*(n+1)/2, it.count(1))))

with open('words.txt') as wordfile:
	words = wordfile.read().replace('"', '').split(',')
	result = len(
		filter(
			lambda x: x in TRIANGLE_NUMBERS,
			map(
				lambda a: reduce(op.add, map(lambda c: ord(c)-ord('A')+1, a)),
				words
			)
		)
	)

print(result)
