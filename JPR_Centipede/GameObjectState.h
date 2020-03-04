#ifndef GAMEOBJECTSTATE_H
#define GAMEOBJECTSTATE_H
#pragma once
#include "ObjectData.h"
#include "GameEvent.h"
#include "ObjectCommand.h"

class GameObjectState
{

public:
	virtual void executeEventListeners(vector<GameEventListener*>& events, float elapsedTime) = 0;
	virtual void executeCommand(queue<ObjectCommand*>& commands, float elapsedTime) = 0;

};

#endif

