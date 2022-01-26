#include <stdio.h>

int add(int, int);
int sub(int, int);

int main(void) {
	//int (*pf)(int, int) 
	int (*pf[2])(int, int) = { sub, add };
	pf[0] = &add;
	pf[1] = &sub;

	for (int i = 0; i < 2; i++) {
		pf[i](1, 2);
	}
;}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}
