#!/usr/bin/env python

from itertools import permutations

p = permutations("0123456789")
res = []

for x in p:
	a = ''.join(x)
	if  int(a[1: 4])% 2 == 0 \
	and int(a[2: 5])% 3 == 0 \
	and int(a[3: 6])% 5 == 0 \
	and int(a[4: 7])% 7 == 0 \
	and int(a[5: 8])%11 == 0 \
	and int(a[6: 9])%13 == 0 \
	and int(a[7:10])%17 == 0:
		res.append(int(a))

print sum(res)
