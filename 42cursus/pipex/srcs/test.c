#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/libft/libft.h"

#define BUFSIZE 30

int main(int argc, char *argv[], char **envp)
{
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	printf("%s\n", argv[3]);

	return 0;
}
