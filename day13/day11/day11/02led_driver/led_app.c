#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char w_buf[12] = "1234";
char r_buf[12] = "";

int main(int argc, const char *argv[])
{
	int fd = open("/dev/myled",O_RDWR);
	if (fd == -1) {
		perror("open");
		return -1;
	}

	write(fd, w_buf, strlen(w_buf));
	
	read(fd, r_buf, sizeof(r_buf));

	close(fd);

	return 0;
}


