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


//int (*f)(int, int) -> int (*fn(param))(int, int)
//how about return??
int (*return_fn_pointer(int num))(int, int)
{
	printf("called\n");
	return &add;
	//return_type (*name(param1, param2))()
}
//but usually typedef

typedef int int_my_32bit;
typedef int FUNC(int, int);
//fn point nickname

//usually like this
FUNC* myfunc(int a, int b)
{

}

//or more shorter
typedef int (*PFUNC)(int, int);
PFUNC myfunc2(int a, int b)
{

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



