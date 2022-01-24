#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM 20

//int a = 0;

int* getRandNum(int n_range, int size, int arr[])
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % n_range;
    }
    return arr;
}

int main(void) 
{
    int num[NUM];
    int* ret_ptr;
    double sum = 0;

    srand((unsigned int)time(0));

    ret_ptr = getRandNum(20, NUM, num);

    for (int i = 0; i < NUM; i++) {
        sum = sum + (double)ret_ptr[i];
    }

    sum = sum / NUM;

    printf("%.2lf", sum);

    return 0;
}

