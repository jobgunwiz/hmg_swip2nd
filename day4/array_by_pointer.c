#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//just only start address is passed
void ary_sth(char arr[][5], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char arr[2][5] = { "abcde", "12345"};
	
	char* p_char_ele = NULL;
	char(*p_char_set)[5] = NULL;

	ary_sth(arr, 2, 5);

	char* ch_0_0_addr, *ch_0_1_addr, *ch_1_0_addr;
	
	char(*ch)[5];	//example

	ch_0_0_addr = (char*)malloc(sizeof(char) * 5);
	ch_0_1_addr = (char*)malloc(sizeof(char) * 5);
	ch_1_0_addr = (char*)malloc(sizeof(char) * 5);


	char** ppChar;	//real
	ppChar = (char**)malloc(sizeof(char*) * 2);
	for (int loop = 0; loop < 2; loop++) {
		ppChar[loop] = (char*)malloc(sizeof(char) * 5);
	}

	return 0;
}



