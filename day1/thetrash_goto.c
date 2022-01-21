#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fn1()
{
	// trash code
	int sum = 0;
	int count = 1;

LOOP:
	printf("run\n");
	sum += count;
	count++;
	if (count <= 10)
		goto LOOP;

	printf("SUM is %d\n", sum);
	
}

int main()
{
	fn1();

	return 0;
}
