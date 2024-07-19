#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0, sum = 0;  // 局部变量，变量中的值随机
	do {
		sum += i;
		i++;
	} while(i <= 100);
	printf("sum = %d\n",sum);


	return 0;
}
