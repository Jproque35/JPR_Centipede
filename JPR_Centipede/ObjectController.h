#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#pragma once
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveRightCommand.h"

class ObjectController
{

public:
	virtual void update(float elapsedTime) = 0;

};

#endif

