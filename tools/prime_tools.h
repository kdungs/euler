#ifndef __PRIME_TOOLS__
#define __PRIME_TOOLS__

#include <stdbool.h>
#include <stdlib.h>

#define PRIME_TABLE struct prime_table
#define PT PRIME_TABLE

PT {
	bool *table;
	int N;
};

PT *pt_create(int);
void pt_destroy(PT*);
bool is_prime(int, PT*);
int next_prime(int, PT*);

#endif /* __PRIME_TOOLS__ */
