#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	struct timeval start;
	struct timeval end;
	suseconds_t	usec;

	gettimeofday(&start, NULL);
	usleep(50);
	gettimeofday(&end, NULL);

	printf("start : %ld\n", start.tv_sec);
	printf("end : %ld\n", end.tv_sec);

	usec = end.tv_usec - start.tv_usec;
	printf("%d\n", usec);		// int

	return 0;
}
