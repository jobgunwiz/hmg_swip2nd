#include <stdio.h>

#define ADC_D_BY_PTR *(volatile unsigned int*)0x7ffdf128e89c

void main() {
    volatile unsigned int ADC_D;

    ADC_D = 4;
    ADC_D = ADC_D + 6;
    //ADC_D_BY_PTR = 7;
    //*(&ADC_D) = 7;


    printf("ADC_D is %d at %p\n", ADC_D, &ADC_D);

    unsigned int y = ADC_D + 3;
    unsigned int a = 5;
    y = ADC_D + a + 5;
    printf("y is %d\n", y);

}


