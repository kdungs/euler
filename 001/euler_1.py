#!/usr/bin/env python

e1 = lambda n: sum(filter(lambda x: x%3==0 or x%5==0, xrange(n)))

print('  10: %d' % e1(10))
print('1000: %d' % e1(1000))
