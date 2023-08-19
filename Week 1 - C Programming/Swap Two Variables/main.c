#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"


void swap1(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void swap3(int* a, int* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void swap4(int* a, int* b){
	*a = *a * *b;
	*b = *a / *b;
	*a = *a / *b;
}


int main(){

	int a  = 5;
	int b = 10;
	swap1(&a, &b);
	printf("a = %d , b = %d \n", a, b);
	swap2(&a, &b);
	printf("a = %d , b = %d \n", a, b);
	swap3(&a, &b);
	printf("a = %d , b = %d \n", a, b);
	swap4(&a, &b);
	printf("a = %d , b = %d \n", a, b);

	return 0;
}