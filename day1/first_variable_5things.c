#include <stdio.h>

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

	return 0;
}