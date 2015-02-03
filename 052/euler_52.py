#!/usr/bin/env python

def digits(x):
    return {s for s in '{}'.format(x)}

i = 0
while True:
    i += 1
    d1 = digits(i)
    d2 = digits(2 * i)
    if d1 == d2:
        d3 = digits(3 * i)
        if d1 == d3:
            d4 = digits(4 * i)
            if d1 == d4:
                d5 = digits(5 * i)
                if d1 == d5:
                    d6 = digits(6 * i)
                    if d1 == d6:
                        print(i)
                        break
