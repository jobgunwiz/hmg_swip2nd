#include <stdio.h>

int main()
{
	int num;
	//assign int memeory, and that area's name is 'num'
	num = 10;
	//input 'num' memory area <- data : 10

	printf("num = %d\n", num);

	//plus
	//curiosity : is it assigned only 4 bytes for 'num' variable???

	printf("sizeof %d\n", sizeof(num));
	//sizeof means search for memory size
	//console : 4 -> it means 4 bytes were assigned

	printf("sizeof %d\n", sizeof(int));
	//it is same!

	//how about 'double'??
	printf("sizeof %d\n", sizeof(double));
	//console : 8 -> it means it assign 8 bytes of memory area

	double mynum;
	mynum = 10.01;
	printf("mynum = %f, sizeof %d\n", mynum, sizeof(mynum));


	//page 17
	printf("\n\n");
	int n;
	double d;

	n = 10;
	d= 3.4;
	printf("n = %d\n", n);
	printf("n = %x\n", n);
	printf("d = %f\n", d);
	printf("n = %d d = %f\n", n, d);

	printf("n = %d\n", n);
	printf("n = %4d\n", n);
	printf("n = %04d\n", n);
	printf("\tn = %04d\n", n);

	//self study
	printf("\n");
	printf("d = %.1f\n", d);
	printf("d = %4.f\n", d);
	//self study end

	//path  :/ of \
	//but \ is control escape sequence
	//so we have to use like this \\ : twice!

	//warning! it could be make some logic error..  not indecated by console
	int a = 20;
	int b = 30;

	printf("%d + %d = %d \n", a, b, a + b);
	printf("%d %d\n", a);
	printf("%d\n", a, b);

	return 0;

}