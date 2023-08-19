
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

void maxWater(int *height, int size){

	int maxArea = 0;
	int currentArea = 0;
	int i = 0;
	int j = size - 1;

	while(i < j){
		if(height[i] <= height[j]){
			currentArea = height[i] * (j - i);
			i++;
		}
		else{
			currentArea = height[j] * (j - i);
			j--;
		}

		if(currentArea > maxArea)
			maxArea = currentArea;
	}

	printf("Max = %d", maxArea);
}

int main(){

	int height[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

	maxWater(height, 9);

	return 0;
}
