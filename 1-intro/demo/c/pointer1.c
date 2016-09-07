#include <stdio.h>

int main(int argc, char const *argv[])
{
	int var = 0;
	int* p1 = &var;
	int* p2 = &var;
	printf("address of var: %u\n", &var);
	printf("p1: %u, value: %d\n", p1, *p1);
	printf("p2: %u, value: %d\n", p2, *p2);
	*p1 = 10;
	printf("var: %d, *p1: %d, *p2: %d\n", var, *p1, *p2);

	//var = 11;
	// Now what are *p1 and *p2?
	return 0;
}
