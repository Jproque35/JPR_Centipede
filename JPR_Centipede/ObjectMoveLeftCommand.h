#ifndef OBJECTMOVELEFTCOMMAND_H
#define OBJECTMOVELEFTCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class ObjectMoveLeftCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float xDest = 0.0f;
	void init(GameObject* context);

public:
	ObjectMoveLeftCommand(GameObject* context);
	void reset(GameObject* context);
	void execute(float elapsedTime);
};

#endif

