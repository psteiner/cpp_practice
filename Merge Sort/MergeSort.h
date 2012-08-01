// MergeSort.h
// Class that creates a vector filled with random integers
// provides a function to sort the vector with merge sort
//
// How to Program C++ (Deitel & Deitel)
// Chapter 20 - Searching and Sorting

#pragma once
#include <vector>
using std::vector;

// MergeSort class definition
class MergeSort
{
public:
	// constructor, inits vector
	MergeSort(int);

	// sort vector using merge sort
	void sort();

	// display vector elements
	void displayElements() const;

	// destructor
	~MergeSort(void);

private:
	//vector size
	int size;

	// vecotr of ints
	vector<int> data;
	
	// sort subvector
	void sortSubVector( int, int);

	// merge two sorted vectors
	void merge(int, int, int, int);

	// display subvector
	void displaySubVector(int, int) const;
};

