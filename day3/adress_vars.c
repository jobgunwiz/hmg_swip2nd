#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int global_var;

void recur_call(int count)
{
	int local_recur_v;
	static int static_local_recur_v;
	int array[255];
	int *dynamic_ptr;

	if(count >= 20){
		return;
	}
	dynamic_ptr = (int*)calloc(255, sizeof(int));
	printf("recur call count %3d, count: %p, local_recur_v: %p\n",count, &count, &local_recur_v);
	printf("static_local_recur_vL %p, array %p\n", &static_local_recur_v, &array);
	printf("dyanmic_ptr: %p\n", dynamic_ptr);

	
	recur_call(count+1);
}
//function has a address -> fn pointer...?


int main()
{
	int local_var;
	static int static_local;

	printf("addr main(): %p\n", main);
	printf("addr global_var: %p\n", &global_var);

	printf("addr local_val: %p\n", &local_var);
	printf("addr static_val: %p\n", &static_local);

	recur_call(0);

	return 0;
}

// low) code - data - heap - stack (high
// 	compile time//
// 		    //runtime
