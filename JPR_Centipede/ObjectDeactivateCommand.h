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
	void execute(float elapsedTime);

};
#endif;

