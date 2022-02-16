// hello.c
#include <stdio.h>

extern void foo();
extern void go_home();

int money;

int main() {
    printf("Hello, world!\n");
    foo();
    money = 1000;
    go_home();

    printf("my money %d", money);

    return 0;
}

