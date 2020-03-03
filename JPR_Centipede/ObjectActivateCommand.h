#ifndef OBJECTACTIVATECOMMAND_H
#define OBJECTACTIVATECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectActivateCommand :
	public ObjectCommand
{

private:
	ObjectData* context;

public:
	ObjectActivateCommand(ObjectData* context);
	ObjectActivateCommand(const ObjectActivateCommand& obj);
	~ObjectActivateCommand();
	ObjectActivateCommand& operator=(const ObjectActivateCommand& obj);

	void execute(float elapsedTime);

};

#endif

