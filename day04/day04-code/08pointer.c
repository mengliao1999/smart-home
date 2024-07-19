#include <stdio.h>

int main(int argc, const char *argv[])
{
	char ch = 'A';
	char *p_c = &ch;
	
	printf("ch = %c &ch = %p length = %d\n", 
			ch, &ch, sizeof(char));
	printf("*p_c = %c p_c = %p length = %d\n", 
			*p_c, p_c, sizeof(char *));
	printf("&p_c = %p\n", &p_c);

	int a = 0x12345678;
	int *p = &a;
	printf("a = %#x &a = %p length = %d\n", 
			a, &a, sizeof(int));
	printf("*p = %#x p = %p length = %d\n", 
			*p, p, sizeof(int *));
	printf("&p = %p\n", &p);
	return 0;
}


