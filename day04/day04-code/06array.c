#include <stdio.h>
int main(int argc, const char *argv[])
{
	int arr[5] = {0};
	int i = 0;
	for (i = 0; i < sizeof(arr)/sizeof(int); i++) {
		scanf("%d" , &arr[i]);
	}
	for (i = 0; i < sizeof(arr)/sizeof(int); i++) {
		printf("%d  " , arr[i]);
	}
	printf("\n");
	return 0;
}
