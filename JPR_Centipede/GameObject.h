#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "GameEvent.h"
#include "GameObjectState.h"
#include "CommandFactory.h"
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveRightCommand.h"

class GameObject
{

protected:
	GameObjectState* state;

	void executeCommand(float elapsedTime);
	virtual void preUpdate(float elapsedTime) = 0;
	virtual void postUpdate(float elapsedTime) = 0;

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
	void update(float elapsedTime);

};

#endif

