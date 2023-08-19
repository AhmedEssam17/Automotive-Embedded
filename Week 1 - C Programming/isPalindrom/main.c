
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

int isPalindrom(int num){

	int temp = num;
	int reversed = 0;
	int remainder = 0;

	while(temp != 0){
		remainder = temp % 10;
		reversed = (reversed * 10) + remainder;
		temp = temp / 10;
	}

	if(reversed == num){
		return 1;
	}
	else{
		return 0;
	}
}

void unitTest(int num, int result){

	int test = isPalindrom(num);

	if(test == result){
		printf("Test Case Passed\n\n");
	}
	else{
		printf("Test Case Failed\n\n");
	}
}

int main(){

	int num[7] = {12321, 111, 1000, 1234, 17171, 19991, 99999};
	int result[7] = {1, 1, 0, 0, 1, 1, 1};

	for(int i = 0; i < 7; i++){
		printf("======Unit Test %d======\n", i+1);
		unitTest(num[i], result[i]);
	}

	return 0;
}
