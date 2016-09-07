#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array[3] = {0,0,0};
	int* p = &array[0];
	*p = 1;
	printf("address of array[0]: %u\n", &array[0]);
	printf("p: %u, value: %d\n", p, *p);
	printf("array: {%d, %d, %d}\n", array[0], array[1], array[2]);

	long* p1 = p;
	p1++;
	*p1 = 2;
	printf("address of array[1]: %u\n", &array[1]);
	printf("address of array[2]: %u\n", &array[2]);
	printf("p1: %u, value: %d\n", p1, *p1);
	printf("array: {%d, %d, %d}\n", array[0], array[1], array[2]);

	// int* p2 = p1;
	// p2--;
	// *p2 = 3;
	// What is the content of the array now?
	return 0;
}
