//============================================================================
// Name        : heap.cpp
// Author      : Evgeniya Bautina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include "heap.h"

using namespace std;

void Heap::addElement(int newElement){
	heapArray[numElements] = newElement;
	numElements++;
	int temp = numElements-1;
	while(temp>0){
		int parent = (temp-1)/2;
		if(parent>=0){
			if(heapArray[temp]<heapArray[parent]){
				swap(heapArray[parent], heapArray[temp]);
			}
			else{
				break;
			}
		}
		temp = parent;
	}
}

void Heap::printHeap(){
	for (int i=0;i<arraySize;i++){
		cout<<endl;
		cout<<heapArray[i]<<endl;
		cout<<endl;
	}
}
int main() {
	Heap *heap = new Heap();
	for(int i=0;i<10;i++){
		heap->addElement(10*i);
	}
	heap->printHeap();
	return 0;
}

