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
	vector<GameEventListener*> events;
	queue<ObjectCommand*> commands;

public:
	StateType getType();
	int getCommandQueueSize();
	void clearEventListeners();
	void clearCommands();
	void addEventListener(GameEventListener* event);
	void queueCommand(ObjectCommand* command);
	virtual void executeEventListeners(float elapsedTime) = 0;
	virtual void executeCommand(float elapsedTime) = 0;

};

#endif

