// ParametersandMemoryallocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class CTest
{
public:
	int* mData;
	CTest()
	{
		mData = new int;
	}
	~CTest()
	{
		delete mData;
	}
	void SetData()
	{
		*mData = 5;
	}

	void CallByReference(int* d)
	{
		*mData = *d;
	}
 	void CallUsingReferenceParameter(int& d)
	{
		*mData = d;
	}
	void CallByCopy(int d)
	{
		*mData = d;
	}

};



int main()
{
	CTest *myClass = new CTest();
	myClass->SetData();
	
	std::cout << *myClass->mData << std::endl;


	system("pause");

	int i;
	i = 4;
	myClass->CallByCopy(i);
	cout << i << endl;
	system("pause");

	i = 4;
	myClass->CallByReference(&i);
	cout << i << endl;
	system("pause");

	i = 4;
	myClass->CallUsingReferenceParameter(i);
	cout << i << endl;
	system("pause");

	delete myClass;
    return 0;
}

