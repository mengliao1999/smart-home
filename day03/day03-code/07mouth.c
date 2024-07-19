#include <stdio.h>

int main(int argc, const char *argv[])
{
	int mouth;
	printf("请输入月份 > ");
	scanf("%d", &mouth);
	if (mouth == 1 || mouth == 3 || mouth == 5 || mouth == 7 
			|| mouth == 8 || mouth == 10 || mouth == 12) {
		printf("%d月有31天\n", mouth);
	} else if (mouth == 4 || mouth == 6 || mouth == 9 || mouth == 11) {
		printf("%d月有30天\n", mouth);
	} else if (mouth == 2) {
		printf("%d月有28或着29天\n", mouth);
	} else {
		printf("输入的月份无效\n");
	}

	return 0;
}
