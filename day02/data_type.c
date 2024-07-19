#include <stdio.h> 

int main(int argc, const char *argv[])
{
	// 定义变量 
	char ch = 'a';  // 单引号表示字符  双引号表示字符串
	short s = 1000;
	unsigned int inter = 20000;
	float f = 3.1415;
	
	// 打印变量中的内容，并且打印变量数据类型的大小
	printf("ch = %c , char size = %d\n", ch, sizeof(char));
	printf("s = %d , short size = %d\n", s, sizeof(short));
	printf("inter = %d , int size = %d\n", inter, sizeof(int));
	printf("f = %f , float size = %d\n", f, sizeof(float));

	return 0;
}

