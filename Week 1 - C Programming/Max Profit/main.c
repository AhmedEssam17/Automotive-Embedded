#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

/*
 * int prices[6] = {7, 1, 5, 3, 6, 4};
 *
 *for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(prices[j] - prices[i] > max){
				max = prices[j] - prices[i];
			}
		}
	}
 *
 */

int maximumProfit(int* prices, int n){

	if(n < 1){
		printf("Invalid Price Array");
	}

	int maxProfit = 0;
	int currentProfit = 0;
	int min = prices[0];

	for(int i = 1; i < n; i++){
		if(prices[i] < min){
			min = prices[i];
		}
		if(prices[i] - min >= currentProfit){
			currentProfit = prices[i] - min;
		}
		if(currentProfit > 0){
			maxProfit += currentProfit;
			currentProfit = 0;
			min = prices[i];
		}
	}

	return maxProfit;
}


int main(){

	int prices[6] = {7, 1, 5, 6, 3, 4};
	//int prices[5] = {2, 6, 1, 4, 3};
	//int prices[5] = {7, 6, 4, 3, 1};

	int max = maximumProfit(prices, 6);
	printf("Max Profit = %d", max);

	return 0;
}
