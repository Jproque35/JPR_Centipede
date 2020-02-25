#ifndef OBJECTMOVEUPCOMMAND_H
#define OBJECTMOVEUPCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class ObjectMoveUpCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float yDest = 0.0f;
	void init(GameObject* context);

public:
	ObjectMoveUpCommand(GameObject* context);
	void reset(GameObject* context);
	void execute(float elapsedTime);

};

#endif

