#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int arr[3][2] = { 1,2,3,4,5,6 };
	printf("%d %d\n", arr[1][0], arr[0][1]);	//3 2
	printf("%d %d\n", *(arr[2] + 1), *(arr[1] + 1));	//6 4
	printf("%d %d\n", (*(arr+2))[0], (*(arr+0))[1]);	//5 2
	printf("%d %d\n", **arr, *(*(arr+0) + 0));			//1 1

	return 0;
}



