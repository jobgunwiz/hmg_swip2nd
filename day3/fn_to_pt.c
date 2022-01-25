#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void stst(int pt)
{
	static int hello = 300;

	//printf("###%d", pt);
	int* pt_addr = pt;

	printf("%d\n", pt);

	*pt_addr = &hello;

	printf("%d\n", pt);
}

int main()
{
	int aa = 10;
	int* pointer = &aa;
	
	//printf("%d\n", &pointer);
	printf("%d\n", *pointer);

	stst(&pointer);

	printf("%d\n", *pointer);

	return 0;
}

