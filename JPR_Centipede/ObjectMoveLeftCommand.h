#ifndef OBJECTMOVELEFTCOMMAND_H
#define OBJECTMOVELEFTCOMMAND_H
#pragma once
#include "ObjectCommand.h"

class GameObject;

class ObjectMoveLeftCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float xDest = 0.0f;

public:
	ObjectMoveLeftCommand(GameObject* context);
	ObjectMoveLeftCommand(const ObjectMoveLeftCommand& obj);
	~ObjectMoveLeftCommand();
	ObjectMoveLeftCommand& operator=(const ObjectMoveLeftCommand& obj);

	ObjectCommand* recontextCopy(GameObject* obj);
	void execute(float elapsedTime);
};

#endif

