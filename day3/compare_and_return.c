#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int compare(int a, int b, int* bignum)
{
	if(a > b){
		
		*bignum = a;
		return 1;
	}
	else if(b > a){

		*bignum = b;
		return -1;
	}
	else{
		*bignum = a;
		return 0;
	}
}

int main()
{
	int num1, num2;
	int bigger = 0;
	int result;


	printf("input two numbers\n");
	scanf("%d%d", &num1, &num2);


	result = compare(num1, num2, &bigger);

	if (result > 0){
		printf("num1 is bigger than num2\n");
	}
	else if(result < 0){
		printf("num2 is bigger than num1\n");
	}
	else{
		printf("same numbers\n");
	}
	printf("%d is big number\n", bigger);
	

	return 0;
}
