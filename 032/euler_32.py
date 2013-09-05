#!/usr/bin/env python

import itertools as it


results = set()
possible_lenghts = ((1, 4), (1, 3), (2, 3), (2, 2))
for ll, rl in possible_lenghts:
    perms = it.permutations('123456789', ll + rl)
    for perm in perms:
        l = int(''.join(perm[:ll]))
        r = int(''.join(perm[ll:]))
        p = l * r
        s = str(p)
        if all(_p not in s for _p in perm) and all(s.count(_s) == 1 for _s in s) and '0' not in s and len('{}{}{}'.format(l, r, s)) == 9:
            #results.add((p, l, r))
            results.add(p)

#print(results)
print(sum(results))
