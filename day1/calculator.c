#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void fn1()
{
	char num1, cal, num2;
	int result;

	while (1) {
	printf("input yours (ex. 1 + 2) >> ");
	scanf("%c %c %c", &num1, &cal, &num2);

	if (num1 == 'e') {
		break;
	}

		if (cal == '+') {
			result = num1 + num2 - 48 - 48;
		}
		else if (cal == '-') {
			result = (num1)-(num2);
		}
		else if (cal == '*') {
			result = (num1 - 48) * (num2 - 48);
		}
		else if (cal == '/') {
			if ((num2 - 48) == 0) {
				printf("divide by zero\n");
				continue;
			}
			result = (num1 - 48) / (num2 - 48);
		}
		else if (cal == '%') {
			result = (num1 - 48) % (num2 - 48);
		}
		else {
			printf("input error \n");
			continue;
		}

		printf("result = %d\n", result);
		
		getchar();
	}
}

int main()
{
	fn1();

	return 0;
}
