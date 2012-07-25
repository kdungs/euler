#!/usr/bin/env python

_sum = 0
with open('numbers.txt') as numfile:
	for line in numfile.readlines():
		x = int(line.strip('\n'))
		_sum += x

print(_sum)
