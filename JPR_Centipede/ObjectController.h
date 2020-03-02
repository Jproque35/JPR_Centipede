#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#pragma once
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveRightCommand.h"

class ObjectController
{

protected:
	queue<ObjectCommand*> commands;
	void executeCommand(float elapsedTime);

	virtual void updateSub(float elapsedTime) = 0;

public:
	int commandQueueSize();
	void clearCommands();
	void queueCommand(ObjectCommand* command);
	virtual GameObject* getData() = 0;
	void update(float elapsedTime);

};

#endif

