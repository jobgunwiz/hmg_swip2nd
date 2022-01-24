#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a = 0;

int save(int num)
{
    static int cash = 0;
    
    cash = cash + num;

    if (num >= 0) {
        printf("%d \t \t %d\n", num, cash);
    }
    else {
        printf(" \t %d \t %d\n", -num, cash);
    }



}

int main(void) 
{
    
    printf("===============================\n");
    printf("입금 \t 출금 \t 잔고\n");
    printf("===============================\n");
   
    save(10000);
    save(50000);
    save(-10000);
    save(30000);

    printf("===============================\n");

    return 0;
}

