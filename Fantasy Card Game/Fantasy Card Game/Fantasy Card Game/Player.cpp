#include "Player.h"

using namespace std;

Player::Player()
{
	health = 0;
}

Player::Player(int nhealth)
{
	health = nhealth;
}

void Player::PlayCard()
{

}

int Player::GetHealth()
{
	return health;
}

void Player::SetHealth(int nhealth)
{
	health = nhealth;
}
