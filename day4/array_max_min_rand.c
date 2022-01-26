#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define ARRSIZ 10

void findMaxMin(int* arr, int size, int** max, int** min)
{
	//if same number -> first number will be saved
	for (int i = 0; i < size; i++) {
		if (arr[i] > **max)
			*max = &arr[i];

		if (arr[i] < **min)
			*min = &arr[i];
	}
}

int main()
{
	int arr[ARRSIZ] = { 50, 30, 10, 15, 23, 7, 99, 1, 325, 28 };
	int *max = &arr[0];
	int *min = &arr[0];

	srand((unsigned int)time(NULL));
	//added module : random value
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		printf("%8d", i);
	}
	printf("\n");

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		arr[i] = rand();
		printf("%8d", arr[i]);
	}
	printf("\n");

	findMaxMin(arr, sizeof(arr)/sizeof(int), &max, &min);

	printf("Max : %d[%p], min : %d[%p]\n", *max, max, *min, min);

	//just... myself
	printf("index M : %d, m : %d\n", max - arr, min - arr);

	return 0;
}

