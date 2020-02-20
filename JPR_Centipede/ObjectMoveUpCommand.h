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
	float distTravelled = 0.0f;

public:
	ObjectMoveUpCommand(GameObject* context);
	void execute(float elapsedTime);

};

#endif

