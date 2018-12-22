/*
 * LinearMaxSubarray.c
 *
 *  Created on: 2018. 12. 22.
 *      Author: Hanjun
 */
#include <stdio.h>

void findMaximumSubarrayLinear(int*,int, int*);
//implement the functions below. all they do is print.
void printArray(int*, int, char*);
void printArrayVals(int*, int, int, char*);

int main(void){
	int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int result[3];
	findMaximumSubarrayLinear(A,16,result);
	printArray(result, 3, "iBegin, iEnd, sum");
	printArrayVals(A, result[0], result[1], "maximum nonempty subarray");

	//to keep the program alive after printArray function has returned.
	char key;
	printf("Press any key to quit\n>> ");
	scanf("%c",&key);
	return 0;
}


void findMaximumSubarrayLinear(int* arr, int size, int* res){
	// maximum subarray from A[1, .... ,j]
	int maxSum = arr[0];
	int maxSumLow = 0;
	int maxSumHigh = 0;
	// maximum subarray ending at j, subarray in form A[...j]
	int tailMaxSum = arr[0];
	int tailMaxSumLow = 0;
	int j = 0;

	while(++j < size){
		if(tailMaxSum > 0){
			tailMaxSum += arr[j];
		}else{
			tailMaxSum = arr[j];
			tailMaxSumLow = j;
		}

		if(tailMaxSum > maxSum){
			maxSum = tailMaxSum;
			maxSumLow = tailMaxSumLow;
			maxSumHigh = j;
		}
	}

	res[0] = maxSumLow;
	res[1] = maxSumHigh;
	res[2] = maxSum;
}
