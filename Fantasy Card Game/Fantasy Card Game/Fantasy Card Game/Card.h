#pragma once
#include <string>

using namespace std;

class Card
{
protected:
	int type;
	std::string name;
	int attack;
	int health;

public:
	//Default constructor
	Card();
	//Overload constructor
	Card(int, string, int, int);
	//Default destructor
	~Card();

	void SetHealth(int);
	string GetName();
	int GetHealth();
	int GetAttack();
};

