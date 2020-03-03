#ifndef OBJECTSETPOSITIONCOMMAND_H
#define OBJECTSETPOSITIONCOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectSetPositionCommand :
	public ObjectCommand
{

private:
	ObjectData* context;

public:
	ObjectSetPositionCommand(ObjectData* context);
	ObjectSetPositionCommand(const ObjectSetPositionCommand& obj);
	~ObjectSetPositionCommand();
	ObjectSetPositionCommand& operator=(const ObjectSetPositionCommand& obj);

	void execute(float elapsedTime);

};
#endif
