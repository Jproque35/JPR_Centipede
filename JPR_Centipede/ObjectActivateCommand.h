#ifndef OBJECTACTIVATECOMMAND_H
#define OBJECTACTIVATECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class ObjectActivateCommand :
	public ObjectCommand
{

private:
	GameObject* context;

public:
	ObjectActivateCommand(GameObject* context);
	ObjectActivateCommand(const ObjectActivateCommand& obj);
	~ObjectActivateCommand();
	ObjectActivateCommand& operator=(const ObjectActivateCommand& obj);

	void execute(float elapsedTime);

};

#endif

