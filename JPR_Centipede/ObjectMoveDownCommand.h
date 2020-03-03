#ifndef OBJECTMOVEDOWNCOMMAND_H
#define OBJECTMOVEDOWNCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectMoveDownCommand :
	public ObjectCommand
{

private:
	ObjectData* context = NULL;
	float yDest = 0.0f;

	void init(ObjectData* context);

public:
	ObjectMoveDownCommand(ObjectData* context);
	ObjectMoveDownCommand(const ObjectMoveDownCommand& obj);
	~ObjectMoveDownCommand();
	ObjectMoveDownCommand& operator=(const ObjectMoveDownCommand& obj);

	void reset(ObjectData* context);
	void execute(float elapsedTime);
};

#endif
