#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include "ObjectData.h"
#include "ObjectState.h"

class GameObject
{

protected:
	ObjectData* data = NULL;
	ObjectState* state = NULL;

public:
	~GameObject();
	ObjectData* getData();
	void setState(ObjectState* state);
	void update(float elapsedTime);

};

#endif

