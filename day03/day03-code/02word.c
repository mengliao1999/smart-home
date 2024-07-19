#include <stdio.h>

int main(int argc, const char *argv[])
{
	int x = 10, y = 9;
	int a, b, c;
	a = (--x==y++)?--x:++y;
	b = x++;
	c = y;
	printf("a = %d  b = %d  c = %d\n", a, b, c);
	return 0;
}
