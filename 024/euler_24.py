#!/usr/bin/env python

from itertools import islice, permutations

print(''.join(next(islice(permutations("0123456789"), 1000000-1, None))))
