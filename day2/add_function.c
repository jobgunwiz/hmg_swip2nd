#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

int main(void)
{
	int result;

	result = add(1, 2);

	printf("%d\n", result);

	return 0;
}
