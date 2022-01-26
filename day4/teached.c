#include <stdio.h>

int add(int, int);
int sub(int, int);

int recv_function_pointer(int (*f)(int, int), int num) {
	// 함수를 인자로 사용하는 방법
	int ret = (*f)(30, num);
	return ret;
}

//int (* 함수명(매개변수) )(int, int)

int (*return_function_pointer(int num))(int, int) {
	printf("called\n");
	return &add;
}


typedef int int_my_32bit_int;
typedef int FUNC(int, int);
typedef int (*PFUNC)(int, int);

FUNC* myfunc(int a, int b) {
	return &add;
}

PFUNC myfunc2(int a, int b) {
	return &add;
}

int main(void) {
	int (*pf)(int, int);

	pf = &add; // add 함수 주소 대입

	int ret = 0;
	ret = (*pf)(10, 20); // pf(10, 20)
	printf("%d\n", ret);

	pf = &sub; // sub 함수 주소 대입
	ret = (*pf)(20, 15);
	printf("%d\n", ret);

}

int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}
