#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../tools/prime_tools.h"

bool check_number(int n, PT *tab) {
	int p;

	for (p=1; p<=sqrt(n); p++) {
		if (n%p == 0) {
			if(!is_prime(p+n/p, tab)) {
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	long sum;
	int N, i;
	PT *pt;

	N = 100000000;
	pt = pt_create(N);
	sum = 0L;

	for (i=1; i<N; i++) {
		if(check_number(i, pt)) {
			//printf("%d\n", i);
			sum += i;
		}
	}

	printf("%ld\n", sum);

	pt_destroy(pt);
	return EXIT_SUCCESS;
}
