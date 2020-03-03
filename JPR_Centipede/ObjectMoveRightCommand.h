#ifndef OBJECTMOVERIGHTCOMMAND_H
#define OBJECTMOVERIGHTCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectMoveRightCommand :
	public ObjectCommand
{

private:
	ObjectData* context = NULL;
	float xDest = 0.0f;
	void init(ObjectData* context);

public:
	ObjectMoveRightCommand(ObjectData* context);
	ObjectMoveRightCommand(const ObjectMoveRightCommand& obj);
	~ObjectMoveRightCommand();
	ObjectMoveRightCommand& operator=(const ObjectMoveRightCommand& obj);

	void reset(ObjectData* context);
	void execute(float elapsedTime);
};

#endif

