#include <stdio.h>

extern int increment(int x);
extern int decrement(int x);

int main() {
	int s, y;
	
	s = 1;
	s = increment(s); // s++, therefore, s=2
	y = s + 2; // 2 + 2 = 4
	
	printf("result: %d\n", y);
	return y;
}
	
