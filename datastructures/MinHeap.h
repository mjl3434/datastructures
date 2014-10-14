/*
 * MinHeap.h
 *
 *  Created on: Oct 14, 2014
 *      Author: root
 */

#ifndef MINHEAP_H_
#define MINHEAP_H_

namespace com_marklarwill_datastructuers {

const unsigned int MIN_SIZE = 16;

template <class T>
class MinHeap {

private:
	T** heap;				// An array of pointers to type T
	unsigned int size;		// How many elements are currently in the heap
	unsigned int maxSize;	// The current size of the underlying array

public:
	MinHeap() : size(0), maxSize(MIN_SIZE)
	{
		heap = new T*[MIN_SIZE];
	}

	MinHeap(unsigned int initialSize) : size(0)
	{
        if (initialSize < MIN_SIZE) {
            maxSize = MIN_SIZE;
        }
        else {
            maxSize = roundUpToNearestPowerOfTwo(initialSize);
        }

        heap = new T*[maxSize];
	}

	~MinHeap()
	{
		delete[] heap;
	}

	void add(T* data) {

		if (size == 0) {
			heap[0] = data;
			size++;
			return;
		}

		if (size == maxSize) {
			maxSize *=2;
			T** biggerHeap = new T*[maxSize];
			for (unsigned int i = 0; i < size; i++) {
				biggerHeap[i] = heap[i];
			}
			for (unsigned int i = size; i < maxSize; i++) {
				biggerHeap[i] = nullptr;
			}
			delete[] heap;
			heap = biggerHeap;
		}

		int n = size;

		// Add our element to the end the heap
		heap[n] = data;

        // While we aren't at the root element, and the new value is smaller than its parent
        while (n != 0 && *heap[n] < *heap[parent(n)]) {

            // Swap the new value with it's parent so that the min-heap property is satisfied
        	// and parents are always smaller than their children
            swap(n, parent(n));

            // Continue moving up the tree, checking the heap property at the parent location
            n = parent(n);
        }

        size++;
	}

	T* getMin(void) {
		return heap[0];
	}

	T* removeMin(void) {
		unsigned int root = 0;
		T* rval = heap[0];
		heap[0] = nullptr;
		swap(0, size-1);
		size--;
		heapify(root);
		return rval;
	}

private:

    // heapify ensures that the min-heap property is met on a particular node
    // and all of it's children. Specifically each parent must be less than
    // each of it's children.
	void heapify(unsigned int n) {

		int smallerChild;

        if (isLeaf(n))
            return;

        if (hasTwoChildren(n)) {
			smallerChild = min(leftChild(n), rightChild(n));
        }
        else {
        	smallerChild = leftChild(n);
        }

		// If heap[n] is greater than any of it's children
		if (*heap[smallerChild] < *heap[n]) {

			// Swap heap[n] with it's smaller child
			swap(n, smallerChild);

			// Now adjust the new child to
			heapify(smallerChild);
		}

	}

	void swap(unsigned int a, unsigned int b) {
		T* temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;
	}

	unsigned int max(unsigned int a, unsigned int b) {
		return (*heap[b] < *heap[a]) ? a : b;
	}

	unsigned int min(unsigned int a, unsigned int b) {
		return (*heap[a] < *heap[b]) ? a : b;
	}

	bool isLeaf(unsigned int n) {

		// If a node has children it's not a leaf node
		if ((n*2)+1 < size) {
			return false;
		}
		else {
			return true;
		}
	}

    unsigned int leftChild(unsigned int n) {
        return ((n*2)+1);
    }

    unsigned int rightChild(unsigned int n) {
        return ((n*2)+2);
    }

    bool hasTwoChildren(unsigned int n) {
    	if (size > ((2*n)+2))
			return true;
		return false;
    }

    // The children of the node at A[n] are at A[(2*n)+1] and A[(2*n)+2]
    // E.g. if n = 0, children are 1 and 2
    //      if n = 1, children are 3 and 4
    //      if n = 2, children are 5 and 6
    unsigned int parent(unsigned int n) {

        unsigned int parent = 0;

        if (n == 0) {
            parent = 0;
        }
        else if ((n % 2) == 0) { // Even
            parent = ((n-2)/2);
        }
        else { // Odd
            parent = ((n-1)/2);
        }

        return parent;
    }


    unsigned int roundUpToNearestPowerOfTwo(unsigned int n) {

        // This algorithm was found here:
        // http://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2

        if (n == 0)
            return 1;   // 2^0 == 1
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;

       return n;
    }

};

}

#endif /* MINHEAP_H_ */
