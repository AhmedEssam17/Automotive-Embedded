#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"


/*
 * n = 1 >> 0
 * n = 2 >> 0, 1
 * n >= 3 >> (n-1) + (n-2)
 *
 * Series : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
 */
void fibonacciNumbers(int n){

	if(n < 1){
		printf("Invalid Number");
	}
	else{
		int num1 = 0;
		int num2 = 1;
		int fibNum;

		printf("%d ", num1);

		if(n > 1)
			printf("%d ", num2);

		for(int i = 2; i < n; i++){
			fibNum = num1 + num2;
			printf("%d ", fibNum);
			num1 = num2;
			num2 = fibNum;
		}
	}
}

int main(){

	int n;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d", &n);
	fflush(stdin);

	fibonacciNumbers(n);

	return 0;
}