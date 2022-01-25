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

	return 0;
}

