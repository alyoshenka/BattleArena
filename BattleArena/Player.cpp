#include "Player.h"



Player::Player()
{
}

Player::Player(string nameN, int healthN, int attackPN, int defPN,
	string attackNameN, int teamN, int colorN)
{
	// N stands for new
	// error "cannot convert from 'initializer list' to class
	//hoping constructor fixes this
	name = nameN;
	health = healthN;
	attackP = attackPN;
	defP = defPN;
	attackName = attackNameN;
	team = teamN;
	color = colorN;
}



Player::~Player()
{
}

