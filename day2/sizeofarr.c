#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MYNUM 200

//????????????????

int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int* ptr;
	int* ptr_dy;

	ptr = arr;

	ptr_dy = (int*)malloc(sizeof(int) * 5);

	printf("sizeof full arr: %d\n",sizeof(arr));
	printf("size of one arr : %d\n", sizeof(arr) / sizeof(int));

	printf("how about pt? %d\n", sizeof(ptr));

	printf("%d\n", *(ptr+2));

	printf("value : %d\n", *arr);

	printf("%d\n", sizeof(&(*arr)));

	if (ptr == arr) {
		printf("yes!\n");
	}

	printf("size of dynamic : %d\n", sizeof(ptr_dy));
	ptr_dy[0] = 1;
	ptr_dy[1] = 2;
	ptr_dy[2] = 3;
	ptr_dy[3] = 4;
	ptr_dy[4] = 5;

	for (int i = 0; i < 5; i++) {
		printf("  %d", ptr_dy[i]);
	}
	printf("\n");

	printf("arr: %d, arr[0] : %d\n", arr, &arr[0]);

	return 0;
}

// sizeof는 컴파일 타임 연산자입니다!

