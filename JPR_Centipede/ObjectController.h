#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#pragma once
#include "GameEvent.h"
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveRightCommand.h"

class ObjectController
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
	virtual GameObject* getData() = 0;
	void update(float elapsedTime);

};

#endif

