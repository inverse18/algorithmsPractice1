/*
 ============================================================================
 Name        : mergeSort.c
 Author      : inverse18-Hanjun Kim
 Version     : 1.0.2
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#define MAX_SIZE 20
#define MAX_VAL 1000
void printArray(int*,int,char*);
void merge(int*, int*, int*, int, int);
void mergeSort(int*, int);

int main(void) {
	int A[MAX_SIZE];
	int sizeA = 0;


	printf("Initialize array A: Enter nonnegative integers, end with -1: \n>> ");
	int j = 0;
	while(scanf("%d",&j),getchar(),j!=-1){
		if(sizeA<MAX_SIZE) A[sizeA++]=j;
	}


	printArray(A,sizeA,"A");


	mergeSort(A,sizeA);
	printArray(A,sizeA,"A sorted");
	//to keep the program alive after printArray function has returned.
	char key;
	printf("Press any key to quit\n>> ");
	scanf("%c",&key);
	return 0;
}


void printArray(int *arr,int size, char* title){
	printf("%s",title);
	printf(" [");
	int i=0;
	while(i<size) printf("%d ",arr[i++]);
	printf("%s","]\n");
}


void merge(int *res, int *left, int* right, int n1, int n2){
	printArray(left,n1,"merging left");
	printArray(right,n2,"merging right");
	int i=0, j=0, k=0;
	while(i < n1 && j < n2){
		if(left[i] <= right[j]){
			res[k++] = left[i++];
		}
		else{
			res[k++] = right[j++];
		}
	}
	while(i < n1) res[k++] = left[i++];
	while(j < n2) res[k++] = right[j++];
	printArray(res, n1+n2, "merged into");
	puts("");
}

void mergeSort(int *arr, int size){
	printArray(arr,size,"MergeSort");
	if(size>1){
		int mid = size/2;
		int left[mid];
		for(int i = 0; i < mid; i++) left[i] = arr[i];
		int right[size - mid];
		for(int i = 0; i < size-mid; i++) right[i] = arr[mid+i];
		mergeSort(left, mid);
		mergeSort(right,size-mid);
		merge(arr,left,right,mid,size-mid);
	}
	puts("");
}
