#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/*
 * k_buf[0] = 1 : 红灯 
 * k_buf[0] = 2 : 绿灯 
 * k_buf[0] = 3 : 蓝灯 
 *
 * k_buf[1] = 1 : 输出高
 * k_buf[1] = 0 : 输出低
 * */
char u_buf[2] = "";

int main(int argc, const char *argv[])
{
	int fd = open("/dev/myled",O_RDWR);
	if (fd == -1) {
		perror("open");
		return -1;
	}
	while(1) {
		u_buf[0] = 1;
		u_buf[1] = 1;
		write(fd, u_buf, 2);
		sleep(1);  // 睡眠1s

		u_buf[0] = 1;
		u_buf[1] = 0;
		write(fd, u_buf, 2);
		sleep(1);
	}
	close(fd);

	return 0;
}


