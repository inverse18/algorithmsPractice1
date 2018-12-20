/*
 ============================================================================
 Name        : practice01.c
 Author      : inverse18
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#define MAX_SIZE 4

void printArray(int*,int,char*);
void arraySum(int*,int*,int*,int);


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
