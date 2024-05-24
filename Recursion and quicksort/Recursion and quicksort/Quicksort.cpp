#include "stdafx.h"

#include <iostream>
using namespace std;

// Class to demonstrate quicksort
class CQuickSort
{
public:
	void Display(int data[], int left, int right);
	int Partition(int data[], int left, int right);
	void Quicksort(int data[], int left, int right);
};

// Display the elements of the array between the indices 'left' and 'right'
void CQuickSort::Display(int data[], int left, int right)
{
	for (int i = left; i <= right; ++i)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

// This version of partition assumes that the pivot is the rightmost element of the array
int CQuickSort::Partition(int data[], int left, int right)
{
	// The rightmost element is the pivot.
	int pivotValue = data[right];  // Value of the pivot

	int stackTop = left; // Keeps track of section containing elements smaller than the pivot

						 // go through all of the elements of the array from left through to the element just before right
	for (int i = left; i<right; ++i)
	{
		if (data[i] <= pivotValue)
		{
			swap(data[i], data[stackTop]);
			++stackTop;
		}
	}
	swap(data[stackTop], data[right]);// Move pivot to its final place

									  // return the index of the pivot
	return stackTop;
}

void CQuickSort::Quicksort(int data[], int left, int right)
{
	// The array has less than two elements when right > left
	if (right > left)
	{
		int pivot = Partition(data, left, right);

		Quicksort(data, left, pivot - 1);
		Quicksort(data, pivot + 1, right);
	}
}

const int kSize = 100;
int main()
{
	int myData[kSize] = { 4, 9, 1, 5, 3, 7, 6 };
	int left = 0; // index of start of array
	int right = 6; // index of end of array

	CQuickSort* myQuickSort = new CQuickSort;
	myQuickSort->Quicksort(myData, left, right);
	myQuickSort->Display(myData, left, right);

	delete(myQuickSort);
	system("pause");
}