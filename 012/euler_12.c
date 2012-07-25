#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int num_divisors(int x) {
	int i, sum, sq;

	sum = 0;
	sq = (int) sqrt(x);
	
	for (i=1; i<sq; i++) {
		if (x%i == 0) {
			sum += 2;
		}
	}

	if(x%sq == 0) {
		sum++;
	}

	return sum;
}

int main(int argc, char *argv[]) {
	int t, n;

	t = 1;
	n = 1;

	while(num_divisors(t) <= 500) {
		n++;
		t = n*(n+1)/2;
	}

	printf("%d\n", t);

	return EXIT_SUCCESS;
}
