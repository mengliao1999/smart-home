#include <stdio.h>
int main(int argc, const char *argv[])
{
	int score;
	printf("please input score > ");
	scanf("%d",&score);
	if(score > 100 || score < 0) {
		printf("ERROR\n");
		return -1;    // 退出主函数
	}
	switch(score / 10) {
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	case 5:
	case 4:
	case 3:
	case 2:
	case 1:
	case 0:
		printf("E\n");
		break;
		
	}
	return 0;
}
