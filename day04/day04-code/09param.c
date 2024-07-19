#include <stdio.h>


int main(int argc, const char *argv[])
{
	if(argc != 5) {
		printf("error: ./a.out  param1 param2 param3 param4\n");
		printf("请重新执行程序，并传递正确的参数\n");
		return -1;
	}
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	printf("%s\n", argv[3]);
	printf("%s\n", argv[4]);

	return 0;
}
