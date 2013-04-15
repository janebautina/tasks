/*
 * heap.h
 *
 * Created on: Apr 4, 2013
 * Author: Evgeniya Bautina
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <algorithm>

const int DEFAULT_HEAP_SIZE = 3;

class HeapEmptyException:public std::exception{
public:
  virtual const char* what() const throw() {
    return "The heap is empty!";
  }
  virtual ~HeapEmptyException() throw() {}
};

template <class T>
class Heap{
private:
	int arraySize;
	T *heapArray;
	int numElements;

public:
	int getArraySize() { return arraySize; }
	Heap();
	virtual ~Heap() { delete [] heapArray; }
	void addElement(const T& newElem);
	void printHeap();
	void checkHeap();
	bool checkHeap(int elemNumber);
	T deleteMinElement();
	bool isEmpty() { return numElements == 0; }
};


template <class T> Heap<T>::Heap() {
  arraySize = DEFAULT_HEAP_SIZE;
  numElements = 0;
  heapArray = new T [arraySize];
}

template <class T> void Heap<T>::addElement(const T& newElement) {
  if(numElements<arraySize) {
  heapArray[numElements] = newElement;
  numElements++;
  } else{
    T* newArray = new T[2*arraySize];
    for(int i = 0; i < arraySize; i++) {
      newArray[i] = heapArray[i];
    }
    arraySize *= 2;
    delete [] heapArray;
    heapArray = newArray;
    newArray[numElements] = newElement;
    numElements++;

  }
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
    std::cout << heapArray[i] << " ";
  }
  std::cout << std::endl;
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
    throw HeapEmptyException();
  }
}

#endif /* HEAP_H_ */
