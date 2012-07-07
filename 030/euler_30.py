#!/usr/bin/env python

MAX = int(1e6) # educated guess

result = sum(
	filter(
		lambda x: x == sum(int(a)**5 for a in str(x)),
		xrange(2, MAX)
	)
)

print(result)
