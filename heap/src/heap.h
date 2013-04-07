/*
 * heap.h
 *
 * Created on: Apr 4, 2013
 * Author: Evgeniya Bautina
 */

#ifndef HEAP_H_
#define HEAP_H_
const int DEFAULT_HEAP_SIZE = 10;
class Heap{
private:
	int arraySize;
	int *heapArray;
	int numElements;

public:
	int getArraySize() { return arraySize; }
	Heap();
	virtual ~Heap() { delete [] heapArray; }
	void addElement(int newElem);
	void printHeap();
	void checkHeap();
	bool checkHeap(int elemNumber);
	int deleteMinElement();
	bool isEmpty() {return numElements == 0;}
};



#endif /* HEAP_H_ */
