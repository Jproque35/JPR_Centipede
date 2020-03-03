#ifndef OBJECTMOVELEFTCOMMAND_H
#define OBJECTMOVELEFTCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectMoveLeftCommand :
	public ObjectCommand
{

private:
	ObjectData* context = NULL;
	float xDest = 0.0f;

	void init(ObjectData* context);

public:
	ObjectMoveLeftCommand(ObjectData* context);
	ObjectMoveLeftCommand(const ObjectMoveLeftCommand& obj);
	~ObjectMoveLeftCommand();
	ObjectMoveLeftCommand& operator=(const ObjectMoveLeftCommand& obj);

	void reset(ObjectData* context);
	void execute(float elapsedTime);
};

#endif

