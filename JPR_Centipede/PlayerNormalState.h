#ifndef PLAYERNORMALSTATE_H
#define PLAYERNORMALSTATE_H
#pragma once
#include "GenericState.h"

class Player;

class PlayerNormalState
	: public GenericState 
{

private:
	Player* context;

public:
	PlayerNormalState(Player* context);
	PlayerNormalState(const PlayerNormalState& obj);
	~PlayerNormalState();
	PlayerNormalState& operator=(const PlayerNormalState& obj);

};

#endif