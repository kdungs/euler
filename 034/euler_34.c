#include <stdio.h>

const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int sum_fac_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += FAC[n % 10];
        n /= 10;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int MAX = 9999999,
        sum = 0;
    for (int i = 3; i < MAX; i++) {
        if (i == sum_fac_digits(i)) {
            sum += i;
        }
    }
    printf("sum = %d\n", sum);
}
