#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM 5

int cnt_data = 0;

int* calc_moving_avg(int arr[], int size)
{
    arr[cnt_data % 5] = rand();
    cnt_data++;

    return arr;
}

int main(void) 
{
    int num[NUM] = { 0, };
    int* ret_ptr;
    double sum = 0;
    int cnt = 0;

    srand((unsigned int)time(0));

    while (cnt < 20) {
        ret_ptr = calc_moving_avg(num, NUM);

        //rand nums
        for (int i = 0; i < NUM; i++) {
            printf("%10d", ret_ptr[i]);
            sum = sum + (double)ret_ptr[i];
        }
        printf("\n");

        printf("average : %lf\n", sum / NUM);
        cnt++;
    }
    
    return 0;
}

