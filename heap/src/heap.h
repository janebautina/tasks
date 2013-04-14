/*
 * heap.h
 *
 * Created on: Apr 4, 2013
 * Author: Evgeniya Bautina
 */

#ifndef HEAP_H_
#define HEAP_H_

const int DEFAULT_HEAP_SIZE = 10;
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



#endif /* HEAP_H_ */
