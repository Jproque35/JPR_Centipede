#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H
#pragma once
#include "ObjectController.h"
#include "GameObjectManager.h"
#include "CommandFactory.h"

class GameEventListener
{

public:
	virtual void update(float elapsedTime) = 0;

};
#endif

