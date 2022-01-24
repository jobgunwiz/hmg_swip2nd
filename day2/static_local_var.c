#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int a = 0;

int get_wait_number(int a)
{
    static int cnt = 0;

    ++cnt;

    printf("a : %d\n", a);

    return cnt;
}

int main(void) {
    a = 5;

    printf("%d\n", get_wait_number(3));

    printf("%d\n", get_wait_number(3));

    printf("a : %d\n", a);
    //cnt = 0;

    printf("%d\n", get_wait_number(3));

    return 0;
}

