#include <stdio.h>
#include <string.h>

int main ()
{
	double d;		//double type at stack area 8bytes
	double *pD = &d;	//adress in ptr variable	//32bit - 4 byte at stack area
				//control with 'double' size,, +1 means 8 bytes add
	
	*pD = 12.345;		//pD adress reference... 12.345 input in d area
				//indirect ref.
				//
	d = 10.0000;
		
	printf("%lf\n", *pD);
	
	printf("%p\n", &*pD);
	printf("%p\n", pD);
	
	printf("%p %p %p\n", pD, &pD, *&pD);


	//control...
	unsigned char data[16] = "0123456789ABCDE";	//end is null

	char* pChar = (char*)&data; //16 byte char
	short* pShort = (short*)&data;
	int* pInt = (int*)&data;

	char c = *pChar;		//get no.0 adress value
	short s = *pShort;
	int i = *pInt;

	for (int i = 0; i < (int)strlen(data); i++){
		unsigned char uc = data[i];
		printf("%x ",uc);
	}

	printf("\n");

	printf("char (%x)", c);
	printf("short (%x)", s);
	printf("int (%x)", i);
	//little endian
	//
	printf("\n");

	//targetting
	double target1 = 1.2345;
	double target2 = 6.789;
	double *pDouble = &target1;
	*pDouble = 999.1234;

	pDouble = &target2;
	*pDouble = 123.4567;

	//pointer change
	char* pc;
	int* pn;
	double* pd;

	char chr_v = 'a';
	int int_v = 0;
	double dbl_v = 0.0;

	pc = &chr_v;
	pn = &int_v;
	pd = &dbl_v;

	*pc = 'b';
	*pn = 10;
	*pd = 999.1234;

	printf("%c %d %lf\n", chr_v, int_v, dbl_v);

	return 0;
}

