#include <stdio.h>
int main(int argc, const char *argv[])
{
	int sum = 0, i;
	for (i = 0; i <= 100; i++) {
		sum = sum + i;
	}
	printf("sum = %d\n",sum);
	return 0;
}
