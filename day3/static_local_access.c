#include <stdio.h>


int* test_func()
{
	static int call_counter;
	call_counter = 10;


	return &call_counter;
}

int main()
{
	int *pt;

	pt = test_func();
	printf("[%p] %d\n", pt, *pt);

	return 0;
}
