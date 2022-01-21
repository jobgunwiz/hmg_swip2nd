#include <stdio.h>

typedef char int8;
typedef short int16;
typedef int int32;
//actually, it is usually used by struct
//aka : like nickname
//if you press f12 at visual studio, you can come back here..

int main()
{
	int num = 10;
	//literal : 10
	//memory size is 4 byte
	//and also fix the type of the data : integer

	printf("%d\n", num);
	printf("%d\n", sizeof(num));
	printf("%p\n", &num);
	//address, p is address, and & will give you address
	//address is always changing

	int n1 = 0;
	const int c1 = 0;
	//const have to declare the value of the variable - rule
	//so it could not be used like this
	//const int c2;

	n1 = 10;
	//c1 = 10;//error

	return 0;
}