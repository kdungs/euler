#include <stdio.h>
#include "../tools/prime_tools.h"

int main(int argc, char *argv[])
{
    PT *table = pt_create(100000);  // seems to be a good upper limit

    int max_n = 0,
        max_ab = 0,
        b = 2;
    do {
        for (int a = -999; a < 1000; a++) {
            if (is_prime(1 + a + b, table)) {
                int n = 2;
                while (is_prime(n * n + a * n + b, table)) {
                    n++;
                }
                if (n > max_n) {
                    max_n = n;
                    max_ab = a * b;
                }
            }
        }
        b = next_prime(b, table);
    } while(b < 1000);

    fprintf(stdout, "n = %d\n", max_n);
    fprintf(stdout, "ab = %d\n", max_ab);
    pt_destroy(table);
}
