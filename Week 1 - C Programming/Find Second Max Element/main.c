#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"


/*
 * Second biggest element in a given array:
 *
 * 1) Without sorting:
 * 		max
 * 		preMax
 *
 * 	2) With sorting:
 * 		sort then return arr[size - 2]
 */

void swap(int* a, int* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void withoutSorting(int *arr, int size){

	if(size < 2){
		printf("\nInvalid Array size\n");
		return;
	}

	int max, preMax;

	max = arr[0];
	preMax = INT_MIN;

	for(int i = 1; i < size; i++){
		if(arr[i] > max){
			preMax = max;
			max = arr[i];
		}
		else if(arr[i] < max && arr[i] > preMax){
			preMax = arr[i];
		}
	}

	printf("\nArray without Sorting: \n");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}

	if(preMax == INT_MIN){
		printf("\nNo Second Max Found\n");
	}
	else{
		printf("\nSecond Biggest Element = %d \n", preMax);
	}
}

void withSorting(int *arr, int size){

	if(size < 2){
		printf("Invalid Array size\n");
		return;
	}

	//Bubble Sort
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	printf("Array After Sorting: \n");
	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}

	for(int i = size - 2; i >= 0; i--){
		if(arr[i] != arr[i+1]){
			printf("\nSecond Biggest Element = %d", arr[i]);
			return;
		}
	}

	printf("\nNo Second Max Found\n");

}

int main(){

	//int arr[8] = {5, 3, 9 , 2, 1, 7, 8 , 6};
	int arr[8] = {3,3,1,3,3,3,3,3};
	//int arr[1] = {3};
	//int arr[8] = {-5, -3, -9 , -2, -1, -7, -8 , -6};

	withoutSorting(arr, 8);

	printf("\n===========================\n\n");

	withSorting(arr, 8);

	return 0;
}