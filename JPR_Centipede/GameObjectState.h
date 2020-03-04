#ifndef GAMEOBJECTSTATE_H
#define GAMEOBJECTSTATE_H
#pragma once
#include "ObjectData.h"
#include "GameEvent.h"
#include "ObjectCommand.h"

enum class StateType { Generic, Null, CentipedeHead, CentipedeBody };

class GameObjectState
{

protected:
	StateType type;

public:
	StateType getType();
	virtual void executeEventListeners(vector<GameEventListener*>& events, float elapsedTime) = 0;
	virtual void executeCommand(queue<ObjectCommand*>& commands, float elapsedTime) = 0;

};

#endif

