//============================================================================
// Name        : heap.cpp
// Author      : Evgeniya Bautina
// Version     : 04/06/2013
// Copyright   :
// Description : Class Heap Implementation
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

using namespace std;

void Heap::addElement(int newElement){
  heapArray[numElements] = newElement;
  numElements++;
  int currentElement = numElements - 1;
  while (currentElement > 0) {
    int parent = (currentElement - 1) / 2;
    if (parent >= 0) {
      if (heapArray[currentElement] < heapArray[parent]) {
        swap(heapArray[parent], heapArray[currentElement]);
      }
      else{
        break;
      }
    }
    currentElement = parent;
  }
}

void Heap::printHeap(){
  cout << endl;
  for (int i = 0; i < numElements; i++) {
    cout << heapArray[i] << " ";
  }
  cout << endl;
}

void Heap::checkHeap(){
  for (int i = 0; i < numElements; i++) {
    if (2 * i + 1 < numElements) {
      assert(heapArray[i] <= heapArray[2 * i + 1]);
    }
    if (2 * i + 2 < numElements) {
      assert(heapArray[i] <= heapArray[2 * i + 2]);
    }
  }
}

int main() {
  Heap *heap = new Heap();
  for (int i = 0; i < heap->getArraySize(); i++) {
    int randNumber = rand()%10 + 1;
    heap->addElement(randNumber);
  }
  heap->checkHeap();
  heap->printHeap();
  return 0;
}

