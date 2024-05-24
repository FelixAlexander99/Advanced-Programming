#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;

class Stack
{
private:
	int top;
	string data[SIZE];
public:
	void push(string newData);
	void pop(string &oldData);
	void initialiseStack();
	bool isEmpty();
	bool isFull();
	void displayStack();
	int getLength();
	void displayStackReversed();
	int countData(string searchString);
};

// pushes data onto the stack, increments top.
// input: string newData. The data to be pushed onto the top of the stack.
void Stack::push(string newData)
{
	if (!isFull())
	{
		data[top] = newData;
		++top;
	}
	else
	{
		cout << "stack full" << endl;
	}
}

// pops data from the stack, decrements top.
// output: string &newData (reference parameter). The data to be popped from the top of the stack.
void Stack::pop(string &oldData)
{
	if (!isEmpty())
	{
		--top;
		oldData = data[top];
	}
	else
	{
		cout << "stack empty" << endl;
		oldData = "";
	}
}

// Set up the stack. Set top of the stack to 0.
void Stack::initialiseStack()
{
	top = 0;
}

// Checks to see whether the array is full.
// Returns: true if the array is full, false if the array is not full.
bool Stack::isFull()
{
	if (top >= SIZE)
	{
		return true;
	}
	return false;
}

// Checks to see whether the array is empty.
// Returns: true if the array is empty, false if the array is not empty.
bool Stack::isEmpty()
{
	if (top <= 0)
	{
		return true;
	}
	return false;
}

// Displays all of the items currently on the stack in order from the bottom of the stack
// to the top of the stack.
void Stack::displayStack()
{
	for (int i = 0; i<top; ++i)
	{
		cout << data[i] << endl;
	}
}

// Display the length of the stack
int Stack::getLength()
{
	int length = 0;
	for (int i = 0; i < top; i++)
	{
		length++;
	}
	return length;
}

// Display the stack from the top of the stack to the bottom of the stack
void Stack::displayStackReversed()
{
	for (int i = top; i >= 0; i--)
	{
		cout << data[i] << endl;
	}
}


// Counts how many times a word is found inside stack
int Stack::countData(string searchString)
{
	int numberStringsFound = 0;
	for (int i = 0; i < top; i++)
	{
		if (data[i] == searchString)
		{
			numberStringsFound++;
		}
	}
	return numberStringsFound;
}

int main()
{
	Stack* myStack = new Stack;
	myStack->initialiseStack();

	//push ( insert value into stack )
	myStack->push("red");
	myStack->push("green");
	myStack->push("blue");
	myStack->push("red");

	myStack->displayStack();
	cout << endl;

	cout << myStack->getLength();
	cout << endl;

	myStack->displayStackReversed();
	cout << endl;

	cout << myStack->countData("red");
	cout << endl;

	//pop ( discards value from stack )
	string storedData;
	myStack->pop(storedData);
	cout << "popped: " << storedData << endl;	// blue
	myStack->pop(storedData);
	cout << "popped: " << storedData << endl;	// green
	myStack->pop(storedData);
	cout << "popped: " << storedData << endl;	// red

	delete (myStack);
	system("pause");
}