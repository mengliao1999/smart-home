#include <stdio.h>

int main(int argc, const char *argv[])
{
	int year, mouth;
	printf("please input year and mouth > ");
	scanf("%d%d", &year, &mouth);
	switch(mouth) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		printf("%d mouth 31 days\n", mouth);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("%d mouth 30 days\n",mouth);
		break;
	case 2:
		if ((year % 4 == 0 && year % 100 != 0) || 
				(year % 100 == 0 && year % 400 == 0)) {
			printf("%d mouth 29 days\n", mouth);
		} else {
			printf("%d mouth 28 days\n", mouth);
		}
		break;
	default:
		printf("ERROR\n");
		break;
	}

	return 0;
}
