#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a = 0;

int bin(int num)
{
    //debug code
    if (num == 0) {
        return;
    }

    bin(num / 2);
    printf("%d", num % 2);
}

int main(void) 
{
    
    int user_num;

    printf("enter your digit number : ");
    scanf("%d", &user_num);
    bin(user_num);

    return 0;
}

