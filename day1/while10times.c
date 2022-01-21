#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int i = 0;

	while (1) {
		if (i >= 10) {
			break;
		}
		printf("%2d : ", i + 1);
		printf("hello\n");

		i++;
	}

	return 0;
}
