// Class MergeSort member function definition
//
// How to Program C++ (Deitel & Deitel)
// Chapter 20 - Searching and Sorting
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <cstdlib> // prototypes for rand and srand
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include "MergeSort.h"



MergeSort::MergeSort(int vectorSize)
{
	// validate vectorSize
	size = (vectorSize > 0 ? vectorSize : 10);

	// seed random number generator using current time
	srand(time(0));

	// fill vector with random ints in range 10 to 99
	for (int i = 0; i < size; i++)
	{
		data.push_back(10 + rand() % 90);
	}
}

// split vector, sort subvectors and merge subvectors into sorted vector
void MergeSort::sort()
{
	sortSubVector(0, size - 1);
}


// recursive function to sort subvectors
void MergeSort::sortSubVector(int low, int high)
{
	// test base case: size of vector = 1
	if((high - low) >= 1)
	{
		// calculate middle of vector
		int middle1 = (low + high) / 2;

		// calculate next element over
		int middle2 = middle1 + 1;

		// output split step
		cout << "split:   ";
		displaySubVector(low, high);
		cout << endl << "         ";

		displaySubVector(low, middle1);
		cout << endl << "         ";

		displaySubVector(middle2, high);
		cout << endl << endl;

		// split vector in half; sort each half (recursive calls)
		sortSubVector(low, middle1);
		sortSubVector(middle2, high);

		// merge two sorted vectors after split calls return
		merge(low, middle1, middle2, high);
	}
}

void MergeSort::merge(int left, int middle1, int middle2, int right)
{
	// index into left subvector
	int leftIndex = left;
	// index into right subvector
	int rightIndex = middle2;
	// index into temporary working vector
	int combinedIndex = left;
	// working vector
	vector<int> combined (size);

	// output two subvectors before merging
	cout << "merge:   ";
	displaySubVector(left, middle1);
	cout << endl << "         ";
	displaySubVector(middle2, right);
	cout << endl << "         ";

	// merge vectors until reaching end of either
	while (leftIndex <= middle1 && rightIndex <= right)
	{
		// place smaller of two current elements into result
		// and move to next space in vector
		if(data[leftIndex] <= data[rightIndex])
		{
			combined[combinedIndex++] = data[leftIndex++];
		}
		else
		{
			combined[combinedIndex++] = data[rightIndex++];
		}
	}

	// at the end of left vector
	if(leftIndex == middle2)
	{
		// copy in the rest of the right vector
		while(rightIndex <= right)
		{
			combined[combinedIndex++] = data[rightIndex++];
		}
	}
	else // at end of right vector
	{
		// copy in the rest of the left vector
		while(leftIndex <= middle1)
		{
			combined[combinedIndex++] = data[leftIndex++];
		}
	}

	// copy values back into original vector
	for(int i = left; i <= right; i++)
	{
		data[i] = combined[i];
	}

	// output merged vector
	cout << "         ";
	displaySubVector(left, right);
	cout << endl << endl;
}

// display elements in vector
void MergeSort::displayElements() const
{
	displaySubVector(0, size - 1);
}

// display certain values in vector
void MergeSort::displaySubVector(int low, int high) const
{
	// output spaces for alignment
	for (int i = 0; i < low; i++)
	{
		cout << "   ";
	}

	// output elements left in vector
	for(int i = low; i <= high; i++)
	{
		cout << " " << data[i];
	}
}

MergeSort::~MergeSort(void)
{
}
