#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include "mymalloc.h"
#include <string.h>


void testCaseA() {
	char * ptr[3000];	
	int i,j;
	
	for(i=0;i<3000;i++){
		char * temp=malloc(1);
		ptr[i]=temp;
	}

	for(j=0;j<3000;j++){
		free(ptr[j]);
	}
}

void testCaseB(){
	void* ptr=NULL;
	int i;
	for(i=0;i<3000;i++){
		ptr=malloc(1);
		free(ptr);
	}
}


void testCaseC(){
	void* ptr[3000];
	
	int i=0,j=0,r;
	
	while(i<3000){
		r=rand()%2; //r=0 malloc, 1 free
		
		if(r==0||j==0){
			ptr[j]=malloc(1);
			i++; j++;
		}
		else{
			int block=rand()%j;
			if(block==(j-1)){
				free(ptr[block]);
				ptr[block]=0;
			}
			else{
				free(ptr[r]);
				ptr[r]=ptr[j-1];
				ptr[j-1]=0;
			}
			j--;
		}
	}
	
	while(j > 0){
		free(ptr[j-1]);
		j--;
	}
}

void testCaseD(){
	void* ptr[3000];
	
	int i=0,j=0;
	
	while(i<3000){
		int r=rand()%2;
		if(r==0||j==0){
			int r2 = rand() % 501;
			ptr[j] = malloc(r2);
			i++; j++;
		}

		else{
			int block=rand()%(j);
			if(block==(j-1)){
				free(ptr[block]);
				ptr[block]=0;
			}
			else{
				free(ptr[block]);
				ptr[block]=ptr[j-1];
				ptr[j-1]=0;
			}
			j--;
		}
	}
	while(j>0){
		free(ptr[j-1]);
		j--;
	}
}

void testCaseE() {

	int i,j;

	for (i=0;i<3000;i++) {

		char * ptr = malloc(i);
		free(ptr);

	}

	for (j=0;j<3000;j++) {
		char * ptr = malloc(i);
		free(ptr);
	}
}
void testCaseF() {

	int i;
	char * ptr[3000];
	char * str[] = {"this", "is", "a","test"};

	for(i = 0; i < 3000; i++){		
			char * stringTest = malloc(strlen(str)+1);
			if (stringTest != NULL) { 
				strcpy(stringTest, str);
			}
			ptr[i] = stringTest;
	}
	
	for(i = 0; i < 3000; i++){
		free(ptr[i]);
	}
}


int main(){

	int i;


	unsigned int caseA = 0, caseB = 0, caseC = 0, caseD = 0, caseE = 0, caseF = 0;

	struct timeval start,end;

	for(i = 0; i < 100; i++){

		gettimeofday(&start, NULL);
		testCaseA();
		gettimeofday(&end, NULL);
		caseA += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
		
		gettimeofday(&start, NULL);
		testCaseB();
		gettimeofday(&end, NULL);
		caseB += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
		
		gettimeofday(&start, NULL);
		testCaseC();
		gettimeofday(&end, NULL);
		caseC += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
		
		gettimeofday(&start, NULL);
		testCaseD();
		gettimeofday(&end, NULL);
		caseD += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

		gettimeofday(&start, NULL);
		testCaseE();
		gettimeofday(&end, NULL);
		caseE += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;

		gettimeofday(&start, NULL);
		testCaseF();
		gettimeofday(&end, NULL);
		caseF += (end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec;
		
	}

	int getMean(int testCase){
		return (testCase/=100);
	}

	printf("Mean time TestA: %d microseconds \n", getMean(caseA));
	printf("Mean time TestB: %d microseconds \n", getMean(caseB));
	printf("Mean time TestC: %d microseconds \n", getMean(caseC));
	printf("Mean time TestD: %d microseconds \n", getMean(caseD));
	printf("Mean time TestE: %d microseconds \n", getMean(caseE));
	printf("Mean time TestF: %d microseconds \n", getMean(caseF));

	return 0;
}
