#ifndef OBJECTCOMMAND_H
#define OBJECTCOMMAND_H
#pragma once
#include <iostream>
#include "CommandType.h"

using namespace std;

class GameObject;

class ObjectCommand
{

protected:
	bool finished = false;
	CommandType type = CommandType::Generic;

public:
	virtual ~ObjectCommand();

	bool isFinished();
	CommandType getType();
	virtual void execute(float elapsedTime) = 0;
	virtual ObjectCommand* recontextCopy(GameObject* obj) = 0;

};

#endif

