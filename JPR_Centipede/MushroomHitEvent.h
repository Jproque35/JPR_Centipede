#ifndef MUSHROOMHITEVENT_H
#define MUSHROOMHITEVENT_H
#pragma once
#include "GameEvent.h"
#include "GameObjectManager.h"
#include "MushroomController.h"

class MushroomHitEvent :
	public GameEventListener
{

private:
	MushroomController* context;
	GameObjectManager* gm;

public:
	MushroomHitEvent(GameObjectManager* gm, int i);
	void update(float elapsedTime);

};

#endif

