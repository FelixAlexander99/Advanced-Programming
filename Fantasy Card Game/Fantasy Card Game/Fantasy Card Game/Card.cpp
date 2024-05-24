#include "Card.h"
#include <string.h>

using namespace std;

Card::Card()
{
	type = 0;
	name = " ";
	attack = 0;
	health = 0;
}

Card::Card(int ntype, string nname, int nattack, int nhealth)
{
	type = ntype;
	name = nname;
	attack = nattack;
	health = nhealth;
}

Card::~Card()
{
}

void Card::SetHealth(int nhealth)
{
	health = nhealth;
}

string Card::GetName()
{
	return name;
}

int Card::GetAttack()
{
	return attack;
}

int Card::GetHealth()
{
	return health;
}