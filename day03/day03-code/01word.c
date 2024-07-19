#include <stdio.h>

int main(int argc, const char *argv[]) 
{
	char ch = 'a';
	short s = 1000;
	int i = 10000;
	long int li = 100000;
	long long int lli = 1000000;
	float f = 3.1415;
	double d = 3.141592;

	printf("ch = %c , char size = %d\n", ch, sizeof(char));
	printf("s = %d , short size = %d\n", s, sizeof(short));
	printf("i = %d , int size = %d\n", i, sizeof(int));
	printf("li = %ld , long int size = %d\n", li, sizeof(long int));                                           
	printf("lli = %lld , long long int size = %d\n", lli, sizeof(long long int));
	printf("f = %f , float size = %d\n", f, sizeof(float));
	printf("d = %f , double size = %d\n", d, sizeof(double));

	return 0;
}

