#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#pragma once
#include "CommandType.h"

class GameObject;
class ObjectCommand;

class CommandFactory
{

public:
	static ObjectCommand* makeCommand(CommandType type, GameObject* obj);

};

#endif

