#ifndef GAMEEVENT_H
#define GAMEEVENT_H
#pragma once
#include "ObjectController.h"
#include "GameObjectManager.h"

class GameEvent
{

public:
	virtual void update(float elapsedTime) = 0;

};
#endif

