#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void findMaxMin(int* arr, int size, int** max, int** min)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] > **max)
			*max = &arr[i];

		if (arr[i] < **min)
			*min = &arr[i];
	}
}

int main()
{
	int arr[10] = { 50, 30, 10, 15, 23, 7, 99, 1, 325, 28 };
	int *max = &arr[0];
	int *min = &arr[0];

	findMaxMin(arr, sizeof(arr)/sizeof(int), &max, &min);

	printf("Max : %d[%p], min : %d[%p]\n", *max, max, *min, min);

	//just... myself
	printf("index M : %d, m : %d\n", max - arr, min - arr);

	return 0;
}

