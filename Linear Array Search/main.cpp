// D&D Chapter 7.7 Fig 7.9
// Perform linear search of an array
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int linearSearch (const int [], int, int);

int linearSearchRecursive (const int [], int, int);

void printResult(const int element);

int main()
{
	const   int arraySize = 5; // size of array a
	int a[arraySize];    // create array a
	int searchKey;       // value to locate in array a

	for(int i = 0; i < arraySize; i++)
	{
		a[i] = 2 * i;           // create data
	}

	cout << "Enter integer search key: ";
	cin >> searchKey;

	// attempt to locate searchKey by iterating over array
	cout << "\niterative linear search:" << endl;
	int element = linearSearch(a, searchKey, arraySize);

	// display results of iterative search
	printResult(element);

	// attempt to locate searchKey by recursing over array
	cout << "\nrecursive linear search:" << endl;
	element = linearSearchRecursive(a, searchKey, arraySize);

	// display results of recursive search
	printResult(element);

	return 0;
}

int linearSearch(const int array[], int key, int sizeOfArray)
{
	for(int j = 0; j < sizeOfArray; j++)
	{
		if(array[j] == key)
		{
			return j; // if found, return location of key
		}
	}

	return -1; // key not found
}


int linearSearchRecursive(const int array[], int key, int n)
{
	// key not found
	if(n < 0)
	{
		return -1;
	}

	if(array[n] == key)
	{
		return n;
	}
	else
	{
		linearSearchRecursive(array, key, n - 1);
	}
}

void printResult(const int element)
{
	// display results
	if (element != -1)
	{
		cout << "Found value in element " << element << endl;
	}
	else 
	{
		cout << "Value not found!" << endl;
	}
}