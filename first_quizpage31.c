#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int num1 = 0, num2 = 0;

	printf("input first number : ");
	scanf("%d", &num1);

	printf("input second number : ");
	scanf("%d", &num2);

	printf("you input %d and %d\n", num1, num2);

	printf("sum of your number is : %d\n", num1 + num2);

	return 0;
}