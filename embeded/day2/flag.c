#include <stdio.h>

#define TIMER_EN 0x80
#define f0 0x01
#define f1 0x02
#define f2 0x04
#define f3 0x08
#define f7 0x80

//normally 0 and increse 1,,
//can make start num
enum TMR{
    t_mode0 = 0,
    t_mode1,
    t_reserved1,
    t_reserved2,
    t_reserved3,
    t_reserved4,
    t_reserved5,
    t_enable
};
//control ctrl
//embeded not enum define

void main() {
    unsigned int my_flag = 0x00;

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

    my_flag |= TIMER_EN;
    if(my_flag & TIMER_EN ){
        printf("timer is enabled");
    }
    my_flag = f7|f1|f0;


    //mycode


}


