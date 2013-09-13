#!/usr/bin/env python

from itertools import chain
from scipy.misc import comb

over = 0
for N in range(1, 101):
    for k in range(0, N + 1):
        if comb(N, k, exact=True) > 1e6:
            over += 1
print(over)
