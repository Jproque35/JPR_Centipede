#ifndef MUSHROOMHITEVENT_H
#define MUSHROOMHITEVENT_H
#pragma once
#include "GameEvent.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "Mushroom.h"

class MushroomHitEvent :
	public GameEventListener
{

private:
	Mushroom* context;
	MushroomData* data;
	GameObjectManager* gm;

public:
	MushroomHitEvent(Mushroom* context);
	MushroomHitEvent(const MushroomHitEvent& obj);
	~MushroomHitEvent();
	MushroomHitEvent& operator=(const MushroomHitEvent& obj);

	void update(float elapsedTime);

};

#endif

