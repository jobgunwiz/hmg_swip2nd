#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int, int);
int sub(int, int);

int main()
{
	//함수 포인터 배...열............
	//int (*pf)(int, int);
	int (*pf[2])(int, int) = { sub, add };
	//char* ch[5];
	//pf[0] = &and;
	// pf[0] = and;
	//pf[1] = &sub;
	//all available

	for (int i = 0; i < 2;i++) {
		printf("%d\n",pf[i](1, 2));
	}

	return 0;
}

//like python : decorator

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

//next time: callback
