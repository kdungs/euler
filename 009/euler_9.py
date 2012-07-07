#!/usr/bin/env python

for a in range(1, 998):
	for b in range(a, 999):
		c = 1000 - a - b
		if a**2 + b**2 == c**2 and a+b+c==1000:
			print('a=%d, b=%d, c=%d, abc=%d' % (a, b, c, a*b*c))
			break
