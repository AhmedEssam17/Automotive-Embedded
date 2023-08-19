
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

enum cases{
	out,
	plus,
	minus,
	multiplication,
	division,
	pow,
	fct
};

/*
 * Addition
 * Subtraction
 * Multiplication
 * Division
 * Power
 * Factorial
 */

float add(float x, float y){
	float result = x + y;
	return result;
}

float subtract(float x, float y){
	float result = x - y;
	return result;
}

float multiply(float x, float y){
	float result = x * y;
	return result;
}

float divide(float x, float y){
	float result = x / y;
	if(y == 0){
		printf("Math Error: Cannot divide by Zero");
		return 0;
	}
	return result;
}

float power(float x, float y){
	float result = 1;
	int pow = abs(y);

	for(int i = 1; i <= pow; i++){
		result *= x;
	}

	if(y < 0){
		result = 1 / result;
	}
	return result;
}

float factorial(float x){
	float result = 1;

	if(x < 0){
		printf("Invalid Number to Calculate Factorial\n\n");
		return 0;
	}
	while(x > 1){
		result *= x;
		x--;
	}
	printf("%.2f\n\n", result);
	return result;
}


int main(){

	int choice = 0;
	float x = 0;
	float y = 0;
	float result = 0;
	int flag = 1;

	float (*operation[5])(float, float) = {add, subtract, multiply, divide, power};
	float (*fact)(float) = factorial;

	printf("============================\n");
	printf("=========Calculator=========\n");
	printf("============================\n\n");
	fflush(stdout);

	while(flag != out){
		printf("Choose an Option:\n");
		printf("1) Addition (+)\n");
		printf("2) Subtraction (-)\n");
		printf("3) Multiplication (*)\n");
		printf("4) Division (/)\n");
		printf("5) Power (^)\n");
		printf("6) Factorial (!)\n");
		printf(">>> or 0 to EXIT <<<\n\n");
		printf("Option: ");
		fflush(stdout);

		scanf("%d", &choice);
		fflush(stdin);

		switch(choice){
		case out:
			flag = out;
			break;
		case plus:
		case minus:
		case multiplication:
		case division:
		case pow:
			printf("Enter First Number: ");
			fflush(stdout);
			scanf("%f", &x);
			fflush(stdin);
			printf("Enter Second Number: ");
			fflush(stdout);
			scanf("%f", &y);
			fflush(stdin);
			break;
		case fct:
			printf("Enter a Number: ");
			fflush(stdout);
			scanf("%f", &x);
			fflush(stdin);
			break;
		default:
			printf("Invalid Option Entered\n");
			break;
		}

		if(choice == fct){
			result = fact(x);
		}
		else{
			result = operation[choice - 1](x, y);
		}

		switch(choice){
		case plus:
			printf("%.2f + %.2f = ", x, y);
			break;
		case minus:
			printf("%.2f - %.2f = ", x, y);
			break;
		case multiplication:
			printf("%.2f * %.2f = ", x, y);
			break;
		case division:
			printf("%.2f / %.2f = ", x, y);
			break;
		case pow:
			printf("%.2f ^ %.2f = ", x, y);
			break;
		case fct:
			printf("!%.2f = ", x);
			break;
		}

		printf("%.2f \n\n", result);

		printf("============================\n");

		choice = 0;
	}

	printf("============================\n");
	fflush(stdout);

	return 0;
}

