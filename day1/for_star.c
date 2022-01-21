#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fn1()
{
	int i = 0;
	int j = 0;

	while (i < 10) {
		j = 0;

		while (j < 10) {
			printf("*");
			++j;
		}
		printf("%\n");
		++i;
	}
}

void fn2()
{
	int i = 0;
	int j = 0;

	printf("\n");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 9; i >= 0; i--) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}

}

void fn3()
{
	int i = 0;
	int j = 0;

	printf("\n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		for (;j < 15; j++) {
			printf(" ");
		}
		for (j = 0; j < 10 - i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void fn4()
{
	int i = 0;
	int j = 0;

	printf("\n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		for (;j < 15; j++) {
			printf(" ");
		}
		for (j = 0; j < 10 - i; j++) {
			printf(" ");
		}
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void fn5()
{
	int i = 0;
	int j = 0;

	printf("\n");
	for (i = 0; i < 10; i++) {
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		for (;j < 15; j++) {
			printf(" ");
		}
		
		for (j = 0; j < i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	fn1();
	fn2();
	fn3();
	fn4();
	fn5();

	return 0;
}
