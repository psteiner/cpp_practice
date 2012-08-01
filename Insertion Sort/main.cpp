#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

void arrayImage(const int data[], const int arraySize);

int main()
{
	// size of data array
	const int arraySize = 10;

	// data array
	int data[arraySize] = { 34, 56, 4, 10, 77, 51, 93, 30, 5, 52 };

	// temp variable to hold insterted element
	int insert;

	cout << "Unsorted array: ";

	// output original array
	arrayImage(data, arraySize);

	// insertion sort
	// loop over the elements of the array
	for (int next = 1; next < arraySize; next++)
	{
		// store the value in the current element
		insert = data[next];

		// initialize location to place element
		int moveItem = next;

		// search for the location in which to put the current element
		while((moveItem > 0) && (data[moveItem - 1] > insert))
		{
			// shoft element one slot to the RIGHT
			data[moveItem] = data[moveItem - 1];
			moveItem--;
		}

		data[moveItem] = insert;
	}

	cout << "\nSorted array:   ";
	arrayImage(data, arraySize);


	return 0;
}

void arrayImage(const int data[], const int arraySize)
{
	cout << "[";
	for(int i = 0; i < arraySize; i++)
	{
		if(i > 0)
		{
			cout << ",";
		}
		cout << setw(3) << data[i];
	}
	cout << "]" << endl;
}

