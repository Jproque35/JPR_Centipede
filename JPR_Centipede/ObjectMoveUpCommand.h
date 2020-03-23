#ifndef OBJECTMOVEUPCOMMAND_H
#define OBJECTMOVEUPCOMMAND_H
#pragma once
#include "ObjectCommand.h"

class GameObject;

class ObjectMoveUpCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float yDest = 0.0f;

public:
	ObjectMoveUpCommand(GameObject* context);
	ObjectMoveUpCommand(const ObjectMoveUpCommand& obj);
	~ObjectMoveUpCommand();
	ObjectMoveUpCommand& operator=(const ObjectMoveUpCommand& obj);

	ObjectCommand* recontextCopy(GameObject* obj);
	void execute(float elapsedTime);

};

#endif

