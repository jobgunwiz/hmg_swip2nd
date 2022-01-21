#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fn1()
{
	int n = 0;
	int sum = 0;
	int oddsum = 0;

	printf("\n fn1\n");

	while (1) {
		scanf("%d", &n);

		if (n == -1) {
			break;
		}

		sum = sum + n;

		if (n % 2 == 1) {
			printf("odd\n");
			oddsum = oddsum + n;
		}
	}

	printf("sum : %d\n", sum);
	printf("oddsum : %d\n", oddsum);
}

void fn2()
{
	int n = 0;
	int sum = 0;
	int oddsum = 0;

	printf("\n fn2\n");

	while (1) {
		scanf("%d", &n);

		if (n == -1) {
			break;
		}

		sum = sum + n;

		if (n % 2 == 0) {
			continue;
		}

		printf("odd\n");
		oddsum = oddsum + n;
	}

	printf("sum : %d\n", sum);
	printf("oddsum : %d\n", oddsum);
}

int main()
{
	fn1();
	fn2();


	return 0;
}
