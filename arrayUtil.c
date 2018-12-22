/*
 * arrayUtil.c
 *
 *  Created on: 2018. 12. 22.
 *      Author: Hanjun
 */



void printArrayVals(int *arr, int iBegin, int iEnd, char* title){
	printf("%s",title);
	printf(" [");
	for(int i = iBegin; i <= iEnd; i++){
		printf("%d ",arr[i]);
	}
	printf("%s","]\n");
}

void printArray(int *arr,int size, char* title){
	printf("%s",title);
	printf(" [");
	int i=0;
	while(i<size) printf("%d ",arr[i++]);
	printf("%s","]\n");
}
