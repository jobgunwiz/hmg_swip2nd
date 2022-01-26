#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int times(int a, int b)
{
	return a * b;
}
int divi(int a, int b)
{
	return a / b;
}

int recv_fn_pointer(int (*f)(int, int), int num)
{
	//fn to use parameter
	int ret = (*f)(30, num);
	return ret;

}

//how about return??
int (*return_fn_pointer(int num))(int, int)
{
	printf("called\n");
	return &add;
	//return_type (*name(param1, param2))()
}

int main()
{
	int (*pf)(int, int);

	pf = &add;

	int return_value = 0;
	return_value = (*pf)(10, 20);	//pf(10,20) also available
	printf("%d\n", return_value);

	pf = &sub;
	return_value = (*pf)(20, 15);
	printf("%d\n", return_value);


	return 0;
}



