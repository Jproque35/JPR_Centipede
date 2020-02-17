#ifndef OBJECTSTATE_H
#define OBJECTSTATE_H
#pragma once
#include "ObjectData.h"

using namespace sf;

class ObjectState
{

public:
	/*
	virtual void checkCollision(ObjectData* obj) = 0;
	virtual void checkCollision(Window* w) = 0;*/
	virtual void update(float elapsedTime) = 0;

};

#endif

