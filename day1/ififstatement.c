#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int score = 0;
	printf("enter your score >> ");
	scanf("%d", &score);

	if (score >= 70) {
		printf("success!\n");
		printf("congret!!\n");
	}
	else {
		if (score >= 60) {
			printf("re-test\n");
		}
		else {
			printf("fail\n");
		}
	}

	printf("thank you!\n");


	return 0;
}
