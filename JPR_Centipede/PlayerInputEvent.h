#ifndef PLAYERINPUTEVENT_H
#define PLAYERINPUTEVENT_H
#pragma once
#include "GameEvent.h"
#include "PlayerController.h"

class PlayerInputEvent :
	public GameEvent
{

private:
	PlayerController* context;
	GameObjectManager* gm;

public:
	PlayerInputEvent(GameObjectManager* gm, int i);
	void update(float elapsedTime);

};

#endif

