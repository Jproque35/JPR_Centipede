#ifndef OBJECTDEACTIVATECOMMAND_H
#define OBJECTDEACTIVATECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class ObjectDeactivateCommand :
	public ObjectCommand
{

private:
	ObjectData* context;

public:
	ObjectDeactivateCommand(ObjectData* context);
	ObjectDeactivateCommand(const ObjectDeactivateCommand& obj);
	~ObjectDeactivateCommand();
	ObjectDeactivateCommand& operator=(const ObjectDeactivateCommand& obj);

	void execute(float elapsedTime);

};
#endif;

