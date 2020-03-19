#ifndef OBJECTMOVERIGHTCOMMAND_H
#define OBJECTMOVERIGHTCOMMAND_H
#pragma once
#include "ObjectCommand.h"

class GameObject;

class ObjectMoveRightCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float xDest = 0.0f;

public:
	ObjectMoveRightCommand(GameObject* context);
	ObjectMoveRightCommand(const ObjectMoveRightCommand& obj);
	~ObjectMoveRightCommand();
	ObjectMoveRightCommand& operator=(const ObjectMoveRightCommand& obj);

	void execute(float elapsedTime);
};

#endif

