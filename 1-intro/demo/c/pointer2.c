#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array[2] = {0, 0};
	int* p = &array[0];
	*p = 1;
	printf("address of array[0]: %u\n", &array[0]);
	printf("p: %u, value: %d\n", p, *p);
	printf("array: {%d, %d}\n", array[0], array[1]);

	p++;
	*p = 2;
	printf("address of array[1]: %u\n", &array[1]);
	printf("p: %u, value: %d\n", p, *p);
	printf("array: {%d, %d}\n", array[0], array[1]);

	//*p--;
	//*p = 3;
	// What is the content of the array now?
	

	return 0;
}
