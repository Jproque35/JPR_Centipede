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
	float distTravelled = 0.0f;
	float xDest = 0.0f;

public:
	ObjectMoveRightCommand(GameObject* context);
	void execute(float elapsedTime);
};

#endif

