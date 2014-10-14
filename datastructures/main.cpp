/*
 * main.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: root
 */

#include <iostream>
#include "MinHeap.h"

using namespace std;
using namespace com_marklarwill_datastructuers;

int main(int argc, char* argv[])
{
	MinHeap<int> minHeapInt;
    int ints[] = { 11, 15, 9, 15, 59, 298, 651, 98, 32, 498, 42317, 87, 218, 921, 784, 129, 802, 348, 97, 12 };
    int int_length = sizeof(ints)/sizeof(ints[0]);

    MinHeap<float> minHeapFloat;
    float floats[] = { 3.73f, 2.98f, 17.53f, 158.30f, 2.17934f, 3.1415963f, 523891.0f };
    int float_length = sizeof(floats)/sizeof(floats[0]);

    // Add our integer data
    for (int i = 0; i < int_length; i++) {
    	minHeapInt.add(&ints[i]);
    }

    // Remove it sorted and print
    cout << "Sorted integers: ";
    for (int i = 0; i < int_length; i++) {
        cout << *(minHeapInt.removeMin()) << " ";
    }
    cout << endl;

    // Add our floating point data
    for (int i = 0; i < float_length; i++) {
    	minHeapFloat.add(&floats[i]);
    }

    // Remove it sorted and print
    cout << "Sorted floating points: ";
    for (int i = 0; i < float_length; i++) {
        cout << *(minHeapFloat.removeMin()) << " ";
    }
    cout << endl;

	return 0;
}



