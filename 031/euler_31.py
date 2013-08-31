#!/usr/bin/env python

def combinations(coins, target, _sum=0):
    if _sum == target:
        return 1
    if _sum > target or len(coins) < 1:
        return 0
    return sum(combinations(coins[i:], target, _sum+coins[i]) for i in range(len(coins)))


print(combinations([200, 100, 50, 20, 10, 5, 2, 1], 200))
