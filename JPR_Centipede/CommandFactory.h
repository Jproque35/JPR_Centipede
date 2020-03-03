#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#pragma once
#include "ObjectCommand.h"
#include "ObjectData.h"

class CommandFactory
{

public:
	static ObjectCommand* makeCommand(CommandType type, ObjectData* obj);

};

#endif

