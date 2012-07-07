#!/usr/bin/env python

import itertools as it

result = it.ifilter(
	lambda i: str(i) == str(i)[::-1],
	sorted(
		map(
			lambda x: x[0]*x[1],
			it.combinations_with_replacement(range(100, 1000), 2)
		),
		reverse=True
	)
).next()

print(result)
