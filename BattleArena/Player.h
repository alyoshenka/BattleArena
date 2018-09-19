#pragma once
#include <string>

using std::string;

class Player
{
public:
	Player();
	~Player();
	Player(string nameN, int healthN, int attackPN, int defPN,
		string attackNameN, int teamN, int colorN);

	// private:
	string name;
	int health;
	int attackP;
	int defP;
	string attackName;
	int team;
	int color; // int??
};

