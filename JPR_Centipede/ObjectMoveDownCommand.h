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
	float distTravelled = 0.0f;

public:
	ObjectMoveDownCommand(GameObject* context);
	void execute(float elapsedTime);
};

#endif
