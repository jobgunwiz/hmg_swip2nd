#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a = 0;

int check_system_on()
{
    static int cnt = 0;

    ++cnt;

    printf("call time : %d\n", cnt);

    return cnt;
}

int main(void) {
    
    while (check_system_on() < 3);

    return 0;
}

