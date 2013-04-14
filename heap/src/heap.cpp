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

template <class T> Heap<T>::Heap() {
  arraySize = DEFAULT_HEAP_SIZE;
  numElements = 0;
  heapArray = new T [arraySize];
}

template <class T> void Heap<T>::addElement(const T& newElement) {
  heapArray[numElements] = newElement;
  numElements++;
  int currentElement = numElements - 1;
  while (currentElement > 0) {
    int parent = (currentElement - 1) / 2;
    if (parent >= 0) {
      if (heapArray[currentElement] < heapArray[parent]) {
        swap(heapArray[parent], heapArray[currentElement]);
      } else {
        break;
      }
    }
    currentElement = parent;
  }
}

template <class T> void Heap<T>::printHeap() {
  for (int i = 0; i < numElements; i++) {
    cout << heapArray[i] << " ";
  }
  cout << endl;
}

template <class T> void Heap<T>::checkHeap() {
  for (int i = 0; i < numElements; i++) {
    assert(checkHeap(i));
  }
}

template <class T> bool Heap<T>::checkHeap(int elemNumber) {
  if((( 2 * elemNumber + 1) < numElements) && (heapArray[elemNumber] > heapArray[2 * elemNumber + 1])) {
    return false;
  } else if((( 2 * elemNumber + 2) < numElements) && (heapArray[elemNumber] > heapArray[2 * elemNumber + 2])) {
    return false;
  } else {
    return true;
  }
}

template <class T> T Heap<T>::deleteMinElement() {
  if(!isEmpty()){
    T minElement = heapArray[0];
    heapArray[0] = heapArray[numElements-1];
    numElements--;
    int currentElement = 0;
    while (currentElement < numElements && !checkHeap(currentElement)) {
      int minDescendant = -1;
      if (2 * currentElement + 1 < numElements) {
        minDescendant = 2 * currentElement + 1;
      }
      if (2 * currentElement + 2 < numElements && (minDescendant == -1 ||
          heapArray[minDescendant] > heapArray[2 * currentElement + 2])) {
        minDescendant = 2 * currentElement + 2;
      }
      swap(heapArray[minDescendant], heapArray[currentElement]);
      currentElement = minDescendant;
    }
    return minElement;
  } else {
    throw "The heap is empty!";
  }
}

int main1() {
  Heap<int> *heap = new Heap<int>();
  for (int i = 0; i < heap->getArraySize(); i++) {
    int randNumber = rand() % 10 + 1;
    heap->addElement(randNumber);
  }
  heap->checkHeap();
  heap->printHeap();
  while(!heap->isEmpty()){
    cout << heap->deleteMinElement() << " ";
    heap->checkHeap();
  }
  cout << endl;
  delete heap;
  return 0;
}

