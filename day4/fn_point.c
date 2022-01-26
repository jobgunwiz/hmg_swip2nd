#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int, int);
int sub(int, int);

int main()
{
	int (*pf)(int, int);
	int(*pl)[10];
	int* pa[10];
	
	pf = add;
	pf(10, 20);

	printf("%d", pf(10, 20));

	return 0;
}

int add(int a, int b)
{
	return 10;
}
int sub(int a, int b)
{
	return 20;
}

