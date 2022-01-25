#include <stdio.h>

void array_1(int* ptr1, int x)
{

}

void array_2(int(*ptr2)[4], int w, int h)
{

}

void swap(int *px, int *py)
{
	*px = *px ^ *py;
	*py = *px ^ *py;
	*px = *px ^ *py;
}

int main()
{
	int x = 20;
	int y = 30;

	swap(&x, &y);

	printf("%d %d\n", x, y);


	return 0;
}
