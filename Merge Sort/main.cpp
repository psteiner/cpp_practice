// Program to test MergeSort class
//
// How to Program C++ (Deitel & Deitel)
// Chapter 20 - Searching and Sorting
#include <iostream>
using std::cout;
using std::endl;

// MergeSort class definition
#include "MergeSort.h"

int main()
{
	// create object to perform mergesort
	MergeSort sortVector(10);

	//print unsorted vector
	cout << "Unsorted vector:" << endl;
	sortVector.displayElements();
	cout << endl << endl;

	// sort the vector
	sortVector.sort();

	// print sorted vector
	cout << "Sorted vector:" << endl;
	sortVector.displayElements();
	cout << endl;

	return 0;

}