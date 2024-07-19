#include <stdio.h>

int main(int argc, const char *argv[])
{
	int g,s,b,res = 100;
	while(res < 1000) {
		g = res % 10;
		s = res / 10 % 10 ;
		b = res / 100 ;
		if (res == g*g*g + s*s*s + b*b*b) {
			printf("%d\n", res);
		}
		res++;
	}
	return 0;
}
