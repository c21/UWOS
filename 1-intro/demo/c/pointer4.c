#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int* p = (int*)malloc(sizeof(int));
	*p = 11;
	printf("p: %u\n", p);
	printf("*p: %d\n", *p);

	free(p);
	printf("p: %u\n", p);
	printf("*p: %d\n", *p);
	*p = 12;
	printf("p: %u\n", p);
	printf("*p: %d\n", *p);

	int* p1 = (int*)malloc(sizeof(int));
	*p1 = 13;
	printf("p1: %u\n", p1);
	printf("*p1: %d\n", *p1);
	printf("*p: %d\n", *p);

	// What if I delete line 11?


	free(p1);

	return 0;
}
