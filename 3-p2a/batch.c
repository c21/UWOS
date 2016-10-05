#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	printf("STD_IN: %d\n", STDIN_FILENO);
	printf("STD_OUT: %d\n", STDOUT_FILENO);
	printf("STD_ERROR: %d\n", STDERR_FILENO);
	
	close(STDIN_FILENO);
	printf("file descripter: %d\n", open("batch", O_RDONLY));

	char* command = (char*)malloc((512) * sizeof(char));
	fgets(command, 512, stdin);

	printf("first line: %s", command);

	return 0;
}