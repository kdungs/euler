#include "stdio.h"
#include "stdlib.h"

int *map_sieve(int N) {
	int i, j;
	int *array;
	array = malloc(sizeof(int)*(N+1));
	if (!array) {
		printf("Error: Could not allocate memory.\n");
		return 0;
	}

	/* Setup array */
	for (i=0; i<=N; i++) {
		array[i] = i;
	}

	/* Run the sieve */
	for (i=2; i<=N/2; i++) {
		for (j=2*i; j<=N; j+=i) {
			array[j] /= array[i];
		}
	}

	return array;
}

long product(int *array, int N) {
	int i;
	long p;
	p = 1L;
	for (i=2; i<=N; i++) {
		p *= array[i];
	}

	return p;
}

int print_array(int *array, int N) {
	int i;
	if (!array || N<1) {
		return 0;
	}
	printf("{\n");
	for (i=0; i<=N; i++) {
		printf("\t%d: %d\n", i, array[i]);
	}
	printf("}\n");
	return 1;
}

long reduced_factorial(int N) {
	int *sieve;
	long p;
	sieve = map_sieve(N);
	p =  product(sieve, N);
	free(sieve);
	return p;
}

int main(int argc, char *argv[]) {
	int *sieve, N;
	N = 500;
	sieve = map_sieve(N);
	print_array(sieve, N);
	printf("%dr! = %ld\n", N, reduced_factorial(N));

	return EXIT_SUCCESS;
}