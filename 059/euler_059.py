#!/usr/bin/env python

from collections import Counter
from itertools import cycle

lettersByFrequency = " etaoinshrdlcumwfgypbvkjxqz"

s_to_i = lambda s: map(ord, s)
i_to_s = lambda i: "".join(map(chr, i))
decypher = lambda t, p: map(lambda c: c[0] ^ c[1], zip(t, cycle(p)))


def load_file(filename):
    with open(filename) as f:
        return [int(x) for x in f.read().split(',')]


def main():
    encrypted = load_file("cipher1.txt")
    groups = (encrypted[n::3] for n in (0, 1, 2))
    counters = (Counter(group) for group in groups)

    for counter in counters:
        mc = counter.most_common(1)[0][0]
        print(i_to_s([mc ^ c for c in s_to_i(lettersByFrequency[:3])]))

    result = sum(decypher(encrypted, s_to_i("god")))
    print(result)


if __name__ == "__main__":
    main()
