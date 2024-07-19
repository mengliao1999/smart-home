#include <stdio.h>

int main(int argc, const char *argv[])
{
	int arr[10] = {0};
	int i, j;
	int tmp;
	for (i = 0; i < sizeof(arr)/sizeof(int);i++) {
		scanf("%d", &arr[i]);
	}
	for(i = 0; i < sizeof(arr)/sizeof(int)-1;i++)
	{
		for(j = 0;j < sizeof(arr)/sizeof(int) - 1 - i; j++)
		{
			if(arr[j] > arr[j+1]) {
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

	for(i = 0; i < sizeof(arr)/sizeof(int);i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	return 0;
}
