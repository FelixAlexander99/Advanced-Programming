// W2IntrotoClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

////////////////////////////////////////////////

struct car
{
	string colour;
	string make;
	float mileage;
	int doors;
};


void CarDisplay(car carName)
{
	cout << carName.colour << endl;
	cout << carName.make << endl;
	cout << carName.mileage << endl;
	cout << carName.doors << endl;
}

////////////////////////////////////////////////

ofstream outfile;
ifstream infile;

///////////////////////////////////////////////

int main()
{
	////////////////////////////////////////////

	car Subaru;
	Subaru.colour = { "green" };
	Subaru.make = { "test" };
	Subaru.mileage = { 12000.5f };
	Subaru.doors = { 4 };

	CarDisplay(Subaru);

	system("pause");

	///////////////////////////////////////////

	outfile.open("myfile.txt");
	outfile << "random efing text cuz I cant copy from word";

	infile.open("copy.txt");
	

	outfile.close;
	infile.close;
	///////////////////////////////////////////
    return 0;
}

