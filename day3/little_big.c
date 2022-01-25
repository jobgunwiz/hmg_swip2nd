#include <stdio.h>

int main()
{
	unsigned int version = 0x1d231231;

	char* major = &version;

	printf("versi : %x\n", *major);
	printf("build : %x\n", *(major+1));
	printf("minor : %x\n", *(major+2));
	printf("major : %x\n", *(major+3));

	printf("release: %d.%d.%d.%d\n", *(major+3), *(major+2), *(major+1), *major);
	//real : bit 

	return 0;
}
