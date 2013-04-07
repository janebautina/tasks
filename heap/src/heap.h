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
	int getArraySize(){return arraySize;}
	void setArraySize(int newSize){arraySize = newSize;}
	Heap(){arraySize = DEFAULT_HEAP_SIZE;numElements = 0; heapArray = new int [arraySize]; }
	virtual ~Heap(){delete []heapArray;}
	void addElement(int newElem);
	void printHeap();
};



#endif /* HEAP_H_ */
