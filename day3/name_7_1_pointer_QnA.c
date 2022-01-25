#include <stdio.h>

int main()
{
	int num1 = 10;
	int num2 = 20;

	int *pnum = &num1;

	*pnum = 20;//changed ... cannot input w/o 0
	pnum = &num2;

	num2 = 100;
	//num2 = &num1;//check

	*pnum = 200;
	//*num2 = 100;//wrong

	printf("1) %d\n",num1);
        printf("2) %d\n",num2);

	printf("3) %p\n",&num1);
	printf("4) %p\n",&num2);
	printf("5) %p\n",&pnum);
	printf("6) %p\n",pnum);
	printf("7) %d\n",*pnum);

	return 0;
}

