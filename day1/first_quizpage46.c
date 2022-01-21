#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int i = 0;

	while (1) {
		if (i >= 100) {
			break;
		}
		printf("%3d\t", i + 1);
		if (i % 5 == 4) {
			printf("\n");
		}
		//printf("hello\n");

		i++;
	}

	i = 0;
	printf("\n");
	while (1) {
		if (i >= 100) {
			break;
		}

		if (!(i % 2)) {
			printf("%5d", i + 1);
		}
		if (i % 10 == 9) {
			printf("\n");
		}
		i++;
	}

	return 0;
}
