#!/usr/bin/env python

MAP = {
	1: 1
}

def length_of_sequence(n):
	if n in MAP:
		return MAP[n]

	l = 1 + length_of_sequence(n/2 if n%2 == 0 else 3*n+1)
	MAP[n] = l
	return l

assert length_of_sequence(13) == 10

result = max(map(lambda x: (length_of_sequence(x), x), xrange(2, 1000000)))

print(result)
