#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "GameEvent.h"
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveRightCommand.h"

class GameObject
{

protected:
	vector<GameEventListener*> events;
	queue<ObjectCommand*> commands;
	void executeCommand(float elapsedTime);

	virtual void updateSub(float elapsedTime) = 0;

public:
	int commandQueueSize();
	void addEventListener(GameEventListener* event);
	void executeEventListeners(float elapsedTime);
	void clearEventListeners();
	void queueCommand(ObjectCommand* command);
	void clearCommands();
	virtual ObjectData* getData() = 0;
	void update(float elapsedTime);

};

#endif

