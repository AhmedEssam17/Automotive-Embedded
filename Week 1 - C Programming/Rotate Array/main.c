
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void reverseArray(int *arr, int start, int end){
	int temp = 0;

	while(start < end){
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void rotateArray(int *arr, int size, int rotate){

	int k = abs(rotate % size);

	if(rotate > 0){
		reverseArray(arr, 0, size - 1 - k);
		reverseArray(arr, size - k, size - 1);
		reverseArray(arr, 0, size - 1);
	}
	else if(rotate < 0){
		reverseArray(arr, 0, k-1);
		reverseArray(arr, k, size - 1);
		reverseArray(arr, 0, size - 1);
	}

	for(int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}

}

int main(){

	int arr[6] = {1, 2, 3, 4, 5, 6};

	rotateArray(arr, 6, 3);

	return 0;
}

