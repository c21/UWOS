#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 1;
	int* p1 = &a;

	long b = 2;
	long* p2 = &b;

	printf("size of p1: %lu\n", sizeof(p1));
	printf("size of *p1(aka size of a): %lu\n", sizeof(*p1));

	printf("size of p2: %lu\n", sizeof(p2));
	printf("size of *p2(aka size of b): %lu\n", sizeof(*p2));

	// int* p3 = p2;
	// What are sizeof(p3) and sizeof(*p3);

	return 0;
}
