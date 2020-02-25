#ifndef OBJECTMOVEDOWNCOMMAND_H
#define OBJECTMOVEDOWNCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class ObjectMoveDownCommand :
	public ObjectCommand
{

private:
	GameObject* context = NULL;
	float yDest = 0.0f;
	void init(GameObject* context);

public:

	ObjectMoveDownCommand(GameObject* context);
	void reset(GameObject* context);
	void execute(float elapsedTime);
};

#endif
