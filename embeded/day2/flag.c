#include <stdio.h>

void main() {
    unsigned char my_flag = 0x00;

    my_flag |= 0x01;
    printf("flag is 0x%02X\n", my_flag);

    my_flag |= 0x08;
    printf("flag is 0x%02X\n", my_flag);

    my_flag |= (1 << 2);
    printf("flag is 0x%02X\n", my_flag);

    //my_flag != 0x80;
    //;;
    my_flag |= 0x80;
    if(my_flag & (0x80)){
        printf("timer is enabled");
    }


    //mycode

    my_flag &= 0x01;
    printf("flag is 0x%02X\n", my_flag);

    my_flag &= 0x08;
    printf("flag is 0x%02X\n", my_flag);

    my_flag &= (1 << 2);
    printf("flag is 0x%02X\n", my_flag);

    my_flag ^= 0x80;
    printf("flag is 0x%02X\n", my_flag);
}


