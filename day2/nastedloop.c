#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MYNUM 200

int main()
{
	int i, j;
	int sum = 0;
	int flag = 0;

	for (i = 0; i < MYNUM; i++) {
		for (j = 0; j < MYNUM; j++) {
			printf("%5d hi\n", j + 1);
			sum = sum + i + 1;
			if (j == MYNUM / 2)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}

	printf("that's it!\n");
	printf("sum of all number is : %d\n", sum);

	return 0;
}

//i don't wanna use goto....
