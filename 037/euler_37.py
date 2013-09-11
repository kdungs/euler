#!/usr/bin/env python

def gen_primes():
    D = {}  
    q = 2  
    while True:
        if q not in D:
            yield q        
            D[q * q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1


def is_prime(x):
    if not hasattr(is_prime, 'generator'):
        is_prime.generator = gen_primes()
        is_prime.primes = set()
        is_prime.upper_limit = 0
    while x > is_prime.upper_limit:
        p = next(is_prime.generator)
        is_prime.primes.add(p)
        is_prime.upper_limit = p
    return x in is_prime.primes


def is_truncatable_prime(x):
    if not is_prime(x) or x < 10:
        return False
    s = str(x)
    return all(map(
        is_prime,
        map(
            int,
            sum(([s[:i], s[i:]] for i in range(1, len(s))), [])
        )
    ))


def take(n, iterable):
    from itertools import islice
    return list(islice(iterable, n))


if __name__ == '__main__':
    print(sum(take(11, filter(is_truncatable_prime, gen_primes()))))
