#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10, b = 20, c;
	/*
	 * int a = 10;
	 * int b = 20;
	 * int c;
	 * */
	int d;
	int aa = 0, bb = 100;
	c = a + b;  // 30
	printf("c = %d\n", c);
	
	/*加加和减减*/
	printf("c = %d\n", c++);  // 30  先使用c中的值，在对c做自加运算
	printf("c = %d\n", c--);  // 31  先使用c中的值，在对c做自减运算
	printf("c = %d\n", ++c);  // 31  先对c做自加运算，在使用c中的值
	printf("c = %d\n", --c);  // 30  先对c做自减运算，在使用c中的值
	
	d = (a>b)?a:b;   
	printf("d = %d\n", d);  // 20
	
	d = (a && b)?a:b;
	printf("d = %d\n", d);  // 10

	d = (aa && bb)?aa:bb;
	printf("d = %d\n", d);  // 100
	return 0;
}
