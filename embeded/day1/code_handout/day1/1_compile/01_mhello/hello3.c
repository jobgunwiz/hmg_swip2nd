// hello.c
#include <stdio.h>

//extern void foo();
extern int money;

int go_home() {
    printf("let's go\n");
    
    //int my_money = money;
    money -= 100;

    return 0;
}

