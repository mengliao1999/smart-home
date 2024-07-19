#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	int fd = open("/dev/mybeep", O_RDWR);
	char cmd = 0;
	while(1) {
		cmd = 1;
		write(fd, &cmd,1);
		sleep(1);
		cmd = 0;
		write(fd, &cmd, 1);
		sleep(1);
	}
	
	close(fd);


	return 0;
}
