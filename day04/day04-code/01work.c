#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i, j;
	for(i = 1; i < 10; i++) {
		for(j = 1; j <= i; j++) {
			printf("%d*%d=%d\t", j,i,j*i);		
		}
		printf("\n");
	}
	return 0;
}
