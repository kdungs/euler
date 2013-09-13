#include <math.h>
#include <stdio.h>
#include "../tools/prime_tools.h"

int goldbach(unsigned int x, PT *t) {
    for (unsigned int i=1; i<sqrt(x/2); i++) {
        if (is_prime(x - 2*i*i, t)) {
            return 0;
        }
    }
    return 1;
}

unsigned int solution(PT *t, unsigned int N) {
    for (unsigned int i=33; i<N; i += 2) {
        if (!is_prime(i, t) && goldbach(i, t)) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    unsigned int N = 1000000;
    PT *table = pt_create(N);

    unsigned int s = solution(table, N);
    if (s) {
        printf("%u\n", s);
    } else {
        printf("No solution found up to %u\n", N);
    }

    pt_destroy(table);
}
