// PointersMemorymanagement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void changeInt(int* funcPointer);

void cancel(int* x, int* y);

int main()
{
	int* pointer = new int; // allocation
	*pointer = 4;	// Dereferencing + assign value of 4
	cout << *pointer << endl; // Outputs 4
	system("pause");

	changeInt(pointer);
	cout << *pointer << endl; // Outputs 10
	system("pause");

	delete pointer; // Deallocation of memory

	int* a = new int;
	int* b = new int;
	cancel(a,b);
	system("pause");
    return 0;
}

void changeInt(int* funcPointer)
{
	*funcPointer = 10; //Dereferencing in a function
}

void cancel(int* x, int* y)
{
	*x = 5;
	*y = 2;
	if (*x < *y) // Set lowest number to 0
	{
		*x = 0;
	}
	else *y = 0;

	cout << *x << endl << *y << endl;
}