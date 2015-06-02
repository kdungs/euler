#!/usr/bin/env python

import primes


def number2digits(x):
    return map(int, str(x))


def digits2number(ds):
    return int(''.join(map(str, ds)))


def combinations(xs):
    xs = list(xs)
    if not xs:
        return []
    head = xs[0]
    tail = xs[1:]
    rest = combinations(tail)
    return [[head]] + [[head] + r for r in rest] + rest


def findOccurences(digit, ds):
    for i, d in enumerate(ds):
        if d == digit:
            yield i


def replacement(digits, digit, positions):
    res = digits[:]
    for pos in positions:
        res[pos] = digit
    return res


def allReplacements(digits, number):
    return map(
        lambda poss: list(map(
            lambda d: digits2number(replacement(digits, d, poss)),
            range(number + 1, 10)
        )),
        combinations(findOccurences(number, digits))
    )


def generatesFamily(order, digit, number):
    hasEnoughPrimes = lambda gens: list(map(
        primes.is_prime,
        gens
    )).count(True) >= (order - 1)
    digits = list(number2digits(number))
    return any(map(hasEnoughPrimes, allReplacements(digits, digit)))


if __name__ == '__main__':
    ps = primes.gen_primes()
    for p in ps:
        if (generatesFamily(8, 0, p) or
            generatesFamily(8, 1, p) or
            generatesFamily(8, 2, p)
        ):
            print(p)
            break
