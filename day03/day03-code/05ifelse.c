#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num;
	printf("please a numbers > ");
	scanf("%d", &num);
	if (num >= 0) {
		printf("%d是一个大于等于0的数字\n", num);
	} else {	
		printf("%d是一个小于0的数字\n", num);
	}

	return 0;
}
