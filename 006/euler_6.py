#!/usr/bin/env python

import numpy as np

xs = np.arange(1, 101)
r = np.sum(xs)**2 - np.sum(xs**2)
print(r)
