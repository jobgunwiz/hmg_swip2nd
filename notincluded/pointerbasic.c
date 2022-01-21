#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n = 10;

	printf("%d\n", n);
	printf("%d\n", sizeof(n));
	printf("%p\n", &n);

	int* p = &n;

	printf("%p\n", &p);
	printf("%p\n", p);
	printf("%d\n", *p);
	printf("%d\n", sizeof(p));
  
  return 0;
}
