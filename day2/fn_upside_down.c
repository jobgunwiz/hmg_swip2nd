#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//so,, we have to write the implementation part up of the whole code... 

int calc(int x, int y)
{
	return add(x, y);
}

int calc_err(int x, int y)
{
	return add(x);//it's err.. but it could be compile.
}

int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

int main(void)
{
	int result;

	result = calc(1, 2);

	printf("%d\n", result);

	result = calc_err(1, 2);

	printf("%d\n", result);

	return 0;
}

//upside-down is okay in c, but not in cpp
