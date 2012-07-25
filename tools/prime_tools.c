#include "prime_tools.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

PT *pt_create(int N) {
	PT *t;
	int i, j;

	if (N <= 1) {
		fprintf (stderr, "%s:%d (%s): N has to be larger than 1.\n", __FILE__, __LINE__, __func__);
		return NULL;
	}

	/* allocate memory */
	t = malloc(sizeof(PT));
	if (!t) {
		fprintf(stderr, "%s:%d (%s): Could not allocate memory for.\n", __FILE__, __LINE__, __func__);
		return NULL;
	}

	t->N = N;
	t->table = malloc(sizeof(bool) * (N+1));
	if (!t->table) {
		fprintf(stderr, "%s:%d (%s): Could not allocate memory.\n", __FILE__, __LINE__, __func__);
		free(t);
		return NULL;
	}

	/* setup table */
	t->table[0] = false;
	t->table[1] = false;
	for (i=2; i<=N; i++) {
		t->table[i] = true;
	}

	/* Sieve of Erastosthenes */
	for (i=2; i<=N/2; i++) {
		if (t->table[i]) {
			for (j=2*i; j<=N; j+=i) {
				t->table[j] = false;
			}
		}
	}

	return t;
}


void pt_destroy(PT *t) {
	if (t) {
		if (t->table) {
			free(t->table);
		}
		free(t);
	}
}

bool is_prime(int x, PT *t) {
	if (!t || !t->table) {
		fprintf(stderr, "%s:%d (%s): No prime table given.\n", __FILE__, __LINE__, __func__);
		return false;
	}

	if (x>t->N) {
		fprintf(stderr, "%s:%d (%s): x=%d is too large for prime table of size N=%d.\n", __FILE__, __LINE__, __func__, x, t->N);
		return false;
	}

	return t->table[x];
}

int next_prime(int last, PT *t) {
	int i;
	if (!t || !t->table) {
		fprintf(stderr, "%s:%d (%s): No prime table given.\n", __FILE__, __LINE__, __func__);
		return 0;
	}

	i = last;
	while(++i <= t->N) {
		if (t->table[i]) {
			return i;
		}
	}

	fprintf(stderr, "%s:%d (%s): %d was the last prime in table of size N=%d.\n", __FILE__, __LINE__, __func__, last, t->N);
	return 0;
}
