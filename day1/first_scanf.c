#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int age = 0;	//assign!
	int tmp;

	printf("enter your age >> ");
	tmp = scanf("%d", &age);	//call by ref. -> memory value change!
	printf("you entered age : %d\n", age);
	//secure coding
	// scanf_s have to input memory size!!

	printf("%d\n", tmp);
	//what is return of scanf??
	//console : 1
	//if input 'a' -> return 0
	//meaning of return : the counter which write how many input
	
	//for example
	int b, c;
	tmp = scanf("%d%d", &b, &c);
	printf("%d\n", tmp);
	//it returns 2

	return 0;
}