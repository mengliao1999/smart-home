#include <stdio.h>
// 函数的名字表示函数的地址
int add(int a, int b) 
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
// 指针函数 ： 返回类型是一个指针类型
int *func(int *a)
{
	return a;
}



int main(int argc, const char *argv[])
{
	// 定义函数指针类型的变量
	// 函数指针不是函数，本质是一个指针类型的变量
	// 函数指针类型的变量可以指向一个函数。
	int (*func_p)(int a, int b);
	// 初始化函数指针变量
	func_p = add;
	printf(" 1 > %d\n", add(100,200));
	printf(" 2 > %d\n", func_p(100,200));

	func_p = sub;
	printf(" 3 > %d\n", sub(300,200));
	printf(" 4 > %d\n", func_p(300,200));

	return 0;
}
