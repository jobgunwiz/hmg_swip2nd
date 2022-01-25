#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void stst(int pt)
{
	static int hello = 300;

	printf("3. %d\n", pt);
	int* pt_addr = pt;

	printf("4. %d\n", *pt_addr);
	printf("4-1 %d\n", pt_addr);

	*pt_addr = &hello;

	printf("5. %d\n", *pt_addr);
	printf("5-1. %d\n", pt_addr);
}

int main()
{
	int aa = 10;
	int* pointer = &aa;
	
	printf("1. %d\n", &pointer);
	printf("2. %d\n", *pointer);
	printf("2-1. %d\n", pointer);

	stst(&pointer);

	printf("6. %d\n", *pointer);

	return 0;
}

