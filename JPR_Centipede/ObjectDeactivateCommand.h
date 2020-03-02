#ifndef OBJECTDEACTIVATECOMMAND_H
#define OBJECTDEACTIVATECOMMAND_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class ObjectDeactivateCommand :
	public ObjectCommand
{

private:
	GameObject* context;

public:
	ObjectDeactivateCommand(GameObject* context);
	ObjectDeactivateCommand(const ObjectDeactivateCommand& obj);
	~ObjectDeactivateCommand();
	ObjectDeactivateCommand& operator=(const ObjectDeactivateCommand& obj);

	void execute(float elapsedTime);

};
#endif;

