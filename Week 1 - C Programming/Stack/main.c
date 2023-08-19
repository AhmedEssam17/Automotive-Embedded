
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

typedef struct{
	int length;
	int top;
	int *arr;
} Stack_t;

typedef enum{
	Stack_valid,
	Stack_empty,
	Stack_full,
	Stack_null
} Stack_Status;

Stack_t* StackInit(uint32_t length){

	Stack_t* StackX = (Stack_t*)malloc(1 * sizeof(Stack_t));
	int* stackArr = (int*)malloc(length * sizeof(int));

	StackX->length = length;
	StackX->arr = stackArr;
	StackX->top = -1;

	return StackX;
}

void StackPush(Stack_t* StackX, uint32_t num){

	if(!StackX->arr){
		printf("Stack is INVALID\n");
		return;
	}

	if(StackX->top == (StackX->length - 1)){
		printf("Stack is FULL\n");
		return;
	}

	StackX->top++;
	StackX->arr[StackX->top] = num;
}

void StackPop(Stack_t* StackX){

	if(!StackX->arr){
		printf("Stack is INVALID\n");
		return;
	}

	if(StackX->top < 0){
		printf("Stack is EMPTY\n");
		return;
	}

	int num = 0;
	num = StackX->arr[StackX->top];
	printf("Pop: %d\n", num);
	StackX->top--;
}

void StackPrint(Stack_t* StackX){

	if(!StackX->arr){
		printf("Stack is INVALID\n");
		return;
	}

	if(StackX->top < 0){
		printf("Stack is EMPTY\n");
		return;
	}
	int num = 0;
	printf("Stack Elements: ");
	while(StackX->top >= 0){
		num = StackX->arr[StackX->top];
		printf("%d ", num);
		StackX->top--;
	}
	printf("\n\n");

	return;
}



int main(){

	Stack_t* StackX = StackInit(5);

	StackPush(StackX, 4);
	StackPush(StackX, 3);
	StackPush(StackX, 5);
	StackPush(StackX, 1);
	StackPush(StackX, 7);
	StackPush(StackX, 9);
	StackPrint(StackX);

	StackPush(StackX, 5);
	StackPush(StackX, 1);
	StackPush(StackX, 7);
	StackPush(StackX, 9);
	StackPop(StackX);
	StackPrint(StackX);

	StackPop(StackX);

	return 0;
}

