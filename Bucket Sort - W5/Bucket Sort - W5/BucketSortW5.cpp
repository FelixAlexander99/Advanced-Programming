#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

// constant for the maximum size of the unsorted array and for each of the buckets.
const int SIZE = 10;

class BucketSort
{
private:
	int unsortedData[SIZE]; // the data to be sorted
	int bucket1[SIZE]; // stack implemention for bucket 1
	int bucket1Top; // stack top for bucket 1
	int bucket2[SIZE]; // stack implemention for bucket 2
	int bucket2Top; // stack top for bucket 2
	int bucket3[SIZE]; // stack implemention for bucket 3
	int bucket3Top; // stack top for bucket 3
public:
	void doSort();
	void initialiseClass(int data[SIZE]);
	void displayBuckets();
};

// Set up the class.
// Set top of each bucket to 0 and then create the array of unsortedData.
// Note that this member function is being used in the place of a constructor.
void BucketSort::initialiseClass(int data[SIZE])
{
	bucket1Top = 0;
	bucket2Top = 0;
	bucket3Top = 0;

	for (int i = 0; i<SIZE; i++)
	{
		unsortedData[i] = data[i];
	}
}


void BucketSort::doSort()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (unsortedData[i] >= 1 && unsortedData[i] <= 10)
		{
			bucket1[i] = unsortedData[i];
		}
		else if (unsortedData[i] >= 11 && unsortedData[i] <= 20)
		{
			bucket2[i] = unsortedData[i];
		}
		else if (unsortedData[i] >= 21 && unsortedData[i] <= 30)
		{
			bucket3[i] = unsortedData[i];
		}
	}
}

// Displays all of the items currently on the stack in order from the bottom of the stack
// to the top of the stack.
void BucketSort::displayBuckets()
{
	cout << "Bucket 1:" << "";
	for (int i = 0; i < SIZE; i++)
	{
		cout<<
	}
}

int main()
{
	BucketSort* myBucket = new BucketSort;

	// This a fudge to deal with the fact that we're avoiding constructors for the time being.
	// However, it works well enough.
	int data[SIZE] = { 4, 13, 23, 12, 7, 28, 9, 15, 2, 21 };
	myBucket->initialiseClass(data);

	myBucket->doSort();

	myBucket->displayBuckets();

	system("pause");
}