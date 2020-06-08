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

	PlayerNormalState(const PlayerNormalState& obj) = delete;
	PlayerNormalState& operator=(const PlayerNormalState& obj) = delete;

public:
	PlayerNormalState(Player* context);
	~PlayerNormalState();

	virtual void update(float elapsedTime) override;

};

#endif