#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

//int a = 0;

int main(void) 
{
    int user_num;
    int cnt = 0;
    int binary_conv = 0;

    scanf("%d", &user_num);

    while (1) {
        binary_conv = binary_conv + (user_num % 2) * pow(10,cnt);

        user_num = user_num / 2;
        cnt++;
        
        //debug
        //printf("%d\n", binary_conv);
        
        if (user_num <= 0) {
            break;
        }
    }
    printf("%d", binary_conv);

    return 0;
}

