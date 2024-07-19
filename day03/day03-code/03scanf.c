#include <stdio.h>
int main(int argc, const char *argv[])
{
	char c;
	scanf("%c", &c);
	printf("c = %c\n", c);
	
	int a;
	scanf("%d", &a);
	printf("a = %d\n", a);

	char str[24];
	scanf("%s", str);
	printf("str = %s\n", str);

	int x, y;
	scanf("%d%d", &x, &y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}
