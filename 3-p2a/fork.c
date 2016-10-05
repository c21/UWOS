#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("main process: %d\n", getpid());

	int rc = fork();

	if (rc == -1) {
		printf("error\n");
	} else if (rc == 0) {
		printf("child process: %d\n", getpid());
	} else {
		printf("I'm the main process: %d, my child is: %d\n", getpid(), rc);
	}

	printf("We are doing the same thing\n");

	return 0;
}