#include <stdio.h>

void main(void) {
    int a = 10;
    int* ap = &a;
    int x, y;

    *ap = 100;

    printf("a is %d accessed by pointer\n", *ap);

    int** ap_p = &ap;
    printf("a is %d at 0x%X\n", *ap, ap);
    printf(" pointer %X which is same to address of a %X\n", ap, &a);
    printf(" accessed by pointer of pointer \n");
    printf(" address of a (%X) is locate in *ap_p (%X)\n", *ap_p, &a);
    printf("finally a is %d accessed by pointer of pointer\n", *(*ap_p));

    scanf("%d %d", &x, &y);
    
}
