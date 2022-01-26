#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n = 0;
	int* p = (int*)malloc(sizeof(int));

	n = 10;
	*p = 10;

	free(p);

	return 0;
}

