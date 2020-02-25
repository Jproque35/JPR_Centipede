#ifndef OBJECTMOVERIGHTCOMMAND_H
#define OBJECTMOVERIGHTCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"
class ObjectMoveRightCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float xDest = 0.0f;
	void init(GameObject* context);

public:
	ObjectMoveRightCommand(GameObject* context);
	void reset(GameObject* context);
	void execute(float elapsedTime);
};

#endif

