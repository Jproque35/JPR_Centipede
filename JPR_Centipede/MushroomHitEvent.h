#ifndef MUSHROOMHITEVENT_H
#define MUSHROOMHITEVENT_H
#pragma once
#include "GameEvent.h"

class Mushroom;
class GameObjectManager;

class MushroomHitEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	Mushroom* context;

public:
	MushroomHitEvent(Mushroom* context);
	MushroomHitEvent(const MushroomHitEvent& obj);
	~MushroomHitEvent();
	MushroomHitEvent& operator=(const MushroomHitEvent& obj);

	void update(float elapsedTime);

};

#endif

