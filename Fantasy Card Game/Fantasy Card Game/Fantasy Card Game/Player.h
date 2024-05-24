#pragma once
class Player
{
protected:
	int health;
public:
	Player();
	Player(int);
	void PlayCard();
	int GetHealth();
	void SetHealth(int);
};

