#ifndef OBJECTSETPOSITIONCOMMAND_H
#define OBJECTSETPOSITIONCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class ObjectSetPositionCommand :
	public ObjectCommand
{

private:
	GameObject* context;

public:
	ObjectSetPositionCommand(GameObject* context);
	ObjectSetPositionCommand(const ObjectSetPositionCommand& obj);
	~ObjectSetPositionCommand();
	ObjectSetPositionCommand& operator=(const ObjectSetPositionCommand& obj);

	void execute(float elapsedTime);

};
#endif
