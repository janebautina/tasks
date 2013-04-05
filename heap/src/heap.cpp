//============================================================================
// Name        : heap.cpp
// Author      : Evgeniya Bautina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;
int * makeHeap(int a[]);
void swap(int *a, int *b);
const int ARRAYSIZE = 10;
int main() {
	int *heapArrayInit = new int[ARRAYSIZE];
	for (int i=0;i<10;i++){
		heapArrayInit[i] =rand()%10+1;
	}
	cout<<"Hello1"<<endl;
	int *heapArrayFinal = new int [ARRAYSIZE];
	cout<<"Hello2"<<endl;
	heapArrayFinal = makeHeap(heapArrayInit);
	for(int i=0;i<ARRAYSIZE;i++){
		cout<<"i"<<i<<" "<<heapArrayFinal[i]<<endl;
	}
	return 0;
}
void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b = temp;
}
int * makeHeap(int heapArrayInit[]){
	int *heapArray = new int[ARRAYSIZE];
	int  heapSize = 0;
	for(int i=0;i<ARRAYSIZE;i++){
		cout << "outer loop, i=" << i << endl;
		heapArray[heapSize] = heapArrayInit[i];
		heapSize++;
		int temp = heapSize-1;
		while(temp>0){
			cout << "inner loop, i=" << i << ", temp=" << temp << endl;
			int parent = (temp-1)/2;
			if(parent>=0){
				if(heapArray[temp]<heapArray[parent]){
					swap(&heapArray[parent], &heapArray[temp]);
				}
				else{
					break;
				}
			}
			temp = parent;
		}
	}
	return heapArray;
}
