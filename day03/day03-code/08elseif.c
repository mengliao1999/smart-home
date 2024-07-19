#include <stdio.h>
int main(int argc, const char *argv[])
{
	int score;
	printf("please input a score > ");
	scanf("%d", &score);
	if(score >= 90 && score <= 100) {
		printf("A\n");
	} else if (score >= 80 && score < 90) {
		printf("B\n");
	} else if(score >= 70 && score < 80) {
		printf("C\n");
	} else if(score >=60 && score < 70) {
		printf("D\n");
	} else if (score < 60 && score > 0) {
		printf("E\n");
	} else {
		printf("error\n");
	}

	return 0;
}
