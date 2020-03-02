#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#pragma once
#include "ObjectCommand.h"
#include "GameObject.h"

class CommandFactory
{

public:
	static ObjectCommand* makeCommand(CommandType type, GameObject* obj);

};

#endif

