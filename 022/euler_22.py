#!/usr/bin/env python

import itertools as it

with open('names.txt') as namefile:
	names = sorted(namefile.read().replace('"', '').split(','))

sumofscores = lambda ns: sum (
	it.imap(
		lambda pos, name: pos * sum(
			map(
				lambda c: ord(c)-ord('A')+1,
				(char for char in name)
			)
		),
		it.count(1), ns
	)
)

print(sumofscores(names))
