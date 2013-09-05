#include <stdio.h>
#include "../tools/prime_tools.h"

int rotate(int x) {
    int pow = 1,
        tmp = x / 10;
    while (tmp > 0) {
        pow *= 10;
        tmp /= 10;
    }
    return x / 10 + (x % 10) * pow;
}


int main(int argc, char *argv[]) {
    int N = 1000000,
        num = 0,
        p = 2;
    PT *table = pt_create(N);

    while (p) {
        int is_circ = 1,
            rot = rotate(p);
        while (p != rot) {
            if (!is_prime(rot, table)) {
                is_circ = 0;
                break;
            }
            rot = rotate(rot);
        }
        if (is_circ) {
            num++;
        }
        p = next_prime(p, table);
    }

    printf("%d\n", num);
    pt_destroy(table);
}
