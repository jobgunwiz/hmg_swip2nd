#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM 10

int call_cnt = 0;

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환

    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환

    return 0;    // a와 b가 같을 때는 0 반환
}

int getRandNum(int n_range)
{
    call_cnt++;
    return rand() % n_range;
}

int* rand_tmp_arr(int n_range, int size, int arr[])
{
    int fil_cnt = 0;
    int tmp;
    int i = 0;

    while (1) {
        tmp = getRandNum(n_range);

        arr[fil_cnt++] = tmp;
        for (i = 0; i < fil_cnt - 1; i++) {
            if (arr[i] == tmp) {
                fil_cnt--;
                break;
            }
        }
        if (fil_cnt >= size) {
            break;
        }
    }

    return arr;
}

int main(void) 
{
    int num[NUM];
    int* ret_ptr;
    double sum = 0;

    srand((unsigned int)time(0));

    ret_ptr = rand_tmp_arr(20, NUM, num);

    //rand nums
    for (int i = 0; i < NUM; i++) {
        printf("%5d", ret_ptr[i]);
    }

    qsort(ret_ptr, NUM, sizeof(int), compare);

    printf("\n");
    for (int i = 0; i < NUM; i++) {
        printf("%5d", ret_ptr[i]);
    }
    printf("\n");
    
    printf("rand fn call : %d", call_cnt);
    
    return 0;
}

