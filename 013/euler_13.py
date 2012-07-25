#!/usr/bin/env python

from operator import add

with open('numbers.txt') as numfile:
	_sum = reduce(add, map(int, numfile.readlines()))
	print(_sum)


"""
# This was my first idea, but I prefer the functional version...
_sum = 0
with open('numbers.txt') as numfile:
	for line in numfile.readlines():
		x = int(line)
		_sum += x

print(_sum)
"""
