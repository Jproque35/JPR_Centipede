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
	~ObjectController();
	void update(float elapsedTime);

};

#endif

