#include <stdio.h>

int main(int argc, const char *argv[])
{
	// 定义int类型数组
	// 数组的长度是10，数组名为arr
	// 并对数组进行初始化
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	// 访问数组中的所有成员并打印到屏幕上
	int i ;
	for(i = 0; i < 10; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	printf("%d %d\n", sizeof(arr), sizeof(int));

	for(i = 0;i < sizeof(arr)/sizeof(int); i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}
