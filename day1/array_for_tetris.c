#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fn1()
{
	int block[4][4] = { {0,0,0,0},{0,1,0,0},{0,1,1,1},{0,0,0,0} };
	
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (block[y][x] == 1) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	fn1();

	return 0;
}
