#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "GameEvent.h"
#include "GameObjectState.h"
#include "CommandFactory.h"

class GameObject
{

protected:
	GameObjectState* state;

	void executeCommand(float elapsedTime);

public:
	virtual void init(float xPos, float yPos) = 0;
	void setState(GameObjectState* state);
	int commandQueueSize();
	void addEventListener(GameEventListener* event);
	void executeEventListeners(float elapsedTime);
	void clearEventListeners();
	int commandsSize();
	void queueCommand(ObjectCommand* command);
	void clearCommands();
	virtual ObjectData* getData() const = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif

