#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i,j;

	for(i = 0; i < 5; i++) {
		for(j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
