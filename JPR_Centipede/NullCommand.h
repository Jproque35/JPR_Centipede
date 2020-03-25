#ifndef NULLCOMMAND_H
#define NULLCOMMAND_H
#pragma once
#include "ObjectCommand.h"

class NullCommand
	: public ObjectCommand
{

private:
	GameObject* context = NULL;

public:
	NullCommand(GameObject* obj);
	NullCommand(const NullCommand& obj);
	~NullCommand();
	NullCommand& operator=(const NullCommand& obj);

	ObjectCommand* recontextCopy(GameObject* obj);
	void execute(float elapsedTime);

};

#endif