#pragma once
#include "GameEvent.h"
#include "GameObjectManager.h"

class MushroomHitEvent :
	public GameEvent
{

private:
	GameObjectManager* gm;

public:
	MushroomHitEvent(GameObjectManager* gm);
	void update(float elapsedTime);

};

