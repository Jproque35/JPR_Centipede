#ifndef OBJECTCOMMAND_H
#define OBJECTCOMMAND_H
#pragma once
#include <iostream>

using namespace std;

class ObjectCommand
{

protected:
	bool finished = false;

public:
	bool isFinished();
	virtual void execute(float elapsedTime) = 0;

};

#endif

