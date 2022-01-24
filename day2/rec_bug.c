#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int a = 0;

int print_hell(int cnt)
{
    //debug code
    if (cnt > 500)
        return;
    
    printf("%d hell\n",cnt);
    print_hell(cnt+1);

}

int main(void) {
    
    print_hell(0);

    return 0;
}

