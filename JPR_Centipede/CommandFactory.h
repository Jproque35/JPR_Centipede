#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#pragma once
#include "CommandType.h"
#include <queue>

using namespace std;

class GameObject;
class ObjectCommand;

class CommandFactory
{

private:
	static CommandFactory* instance;


public:
	static ObjectCommand* makeCommand(CommandType type, GameObject* obj);

};

#endif

