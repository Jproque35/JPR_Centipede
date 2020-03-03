#ifndef OBJECTMOVEUPCOMMAND_H
#define OBJECTMOVEUPCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectMoveUpCommand :
	public ObjectCommand
{

private:
	ObjectData* context = NULL;
	float yDest = 0.0f;
	void init(ObjectData* context);

public:
	ObjectMoveUpCommand(ObjectData* context);
	ObjectMoveUpCommand(const ObjectMoveUpCommand& obj);
	~ObjectMoveUpCommand();
	ObjectMoveUpCommand& operator=(const ObjectMoveUpCommand& obj);

	void reset(ObjectData* context);
	void execute(float elapsedTime);

};

#endif

