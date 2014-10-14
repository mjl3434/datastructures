/*
 * main.cpp
 *
 *  Created on: Oct 14, 2014
 *      Author: root
 */

#include <iostream>
#include "MinHeap.h"

using namespace std;
//using namespace com_marklarwill_datastructuers;

int main(int argc, char* argv[])
{
	MinHeap<int> minHeap;
    int nums[] = { 11, 15, 9, 15, 59, 298, 651, 98, 32, 498, 42317, 87, 218, 921, 784, 129, 802, 348, 97, 12 };
    int length = sizeof(nums)/sizeof(nums[0]);


    // Add our data
    for (int i = 0; i < length; i++) {
        minHeap.add(&nums[i]);
    }

    // Remove it sorted and print
    cout << "Sorted numbers: ";
    for (int i = 0; i < length; i++) {
        cout << *(minHeap.removeMin()) << " ";
    }
    cout << endl;

	return 0;
}



