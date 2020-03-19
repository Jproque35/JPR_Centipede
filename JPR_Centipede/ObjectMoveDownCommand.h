#ifndef OBJECTMOVEDOWNCOMMAND_H
#define OBJECTMOVEDOWNCOMMAND_H
#pragma once
#include "ObjectCommand.h"

class GameObject;

class ObjectMoveDownCommand :
	public ObjectCommand
{

private:
	GameObject* context;
	float yDest = 0.0f;

public:
	ObjectMoveDownCommand(GameObject* context);
	ObjectMoveDownCommand(const ObjectMoveDownCommand& obj);
	~ObjectMoveDownCommand();
	ObjectMoveDownCommand& operator=(const ObjectMoveDownCommand& obj);

	void reset(GameObject* context);
	void execute(float elapsedTime);
};

#endif
