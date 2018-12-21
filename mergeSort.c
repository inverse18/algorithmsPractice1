/*
 ============================================================================
 Name        : mergeSort.c
 Author      : inverse18-Hanjun Kim
 Version     : 1.0.1
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#define MAX_SIZE 20
#define MAX_VAL 1000
void printArray(int*,int,char*);
void arraySum(int*,int*,int*,int);
void merge(int*,int,int,int);
void mergeSort(int*,int,int);

int main(void) {
	int A[MAX_SIZE];
	int B[MAX_SIZE];
	int sizeA = 0;
	int sizeB = 0;
	int C[MAX_SIZE];

	do{
	if(sizeA != sizeB) printf("ERROR:Two arrays need to have equal number of elements");
	printf("Initialize array A: Enter nonnegative integers, end with -1: \n>> ");
	int j = 0;
	while(scanf("%d",&j),getchar(),j!=-1){
		if(sizeA<MAX_SIZE) A[sizeA++]=j;
	}

	printf("Initialize array B: Enter nonnegative integers, end with -1: \n>> ");
	while(scanf("%d",&j),getchar(),j!=-1){
		if(sizeB<MAX_SIZE) B[sizeB++]=j;
	}

	}while(sizeA != sizeB);
	printArray(A,sizeA,"A");
	printArray(B,sizeB,"B");

	arraySum(C,A,B,sizeA);
	printArray(C,sizeA,"Sum of A and B");

	mergeSort(A,0,sizeA-1);
	printArray(A,sizeA,"A sorted");
	//to keep the program alive after printArray function has returned.
	char key;
	printf("Press any key to quit\n>> ");
	scanf("%c",&key);
	return 0;
}


void printArray(int *arr,int size, char* title){
	printf("%s",title);
	printf(" = [");
	int i=0;
	while(i<size) printf("%d ",arr[i++]);
	printf("%s","]\n");
}

void arraySum(int *sum, int*A, int*B, int size){
	int i=0;
	while(i<size) {sum[i]=A[i]+B[i]; i++;}
}

void merge(int *arr, int iBegin, int iMid, int iEnd){
	int n1 = iMid-iBegin+1;
	int n2 = iEnd-iMid;
	int left[n1+1]; int right[n2+1];
	for(int i = 0; i < n1; i++) left[i]=arr[iBegin+i];
	for(int i = 0; i < n2; i++) right[i]=arr[iMid+1+i];
	left[n1] = MAX_VAL+1;
	right[n2] = MAX_VAL+1;
	int i = 0, j = 0;
	for(int k = iBegin; k <= iEnd; k++){
		if(left[i] <= right[j]) arr[k] = left[i++];
		else arr[k] = right[j++];
	}
}

void mergeSort(int *arr,int iBegin, int iEnd){
	if(iBegin < iEnd){
		int iMid = (iBegin+iEnd)/2;
		mergeSort(arr,iBegin,iMid);
		printf("mergeSort(%d,%d) complete\n",iBegin,iMid);
		mergeSort(arr,iMid+1,iEnd);
		printf("mergeSort(%d,%d) complete\n",iMid+1,iEnd);
		merge(arr,iBegin,iMid,iEnd);
		printf("merged(%d,%d,%d)\n",iBegin,iMid,iEnd);
	}
}
