#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fn1()
{
	int sum = 0;
	int input = 0;
	float counter = 0;

	while (1) {
		printf("input your score >> ");
		scanf("%d", &input);
		if (input < 0) {
			break;
		}
		sum = sum + input;
		counter++;
	}

	if (counter == 0) {
		printf("no score input\n");
		return;
	}

	printf("your score average: %f\n", (float)sum / (float)counter);
}

int main()
{
	fn1();

	return 0;
}
