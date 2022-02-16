// hello.c
#include <stdio.h>

//extern void foo();
extern int money;

int go_home() {
    //int n = 0;
    static int n = 0;
    printf("let's go, %d\n", ++n);
    
    //int my_money = money;
    money -= 100;

    return 0;
}

