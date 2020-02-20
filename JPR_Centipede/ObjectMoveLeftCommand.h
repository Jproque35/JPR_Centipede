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
	float distTravelled = 0.0f;

public:
	ObjectMoveLeftCommand(GameObject* context);
	void execute(float elapsedTime);
};

#endif

