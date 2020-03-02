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
	MushroomHitEvent(const MushroomHitEvent& obj);
	~MushroomHitEvent();
	MushroomHitEvent& operator=(const MushroomHitEvent& obj);

	void update(float elapsedTime);

};

#endif

