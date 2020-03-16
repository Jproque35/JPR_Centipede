#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H
#pragma once
#include "GameObject.h"

class ObjectLoader
{

protected:

	virtual void addEvents(GameObject* obj) = 0;

public:
	virtual GameObject* makeObject(ObjectType type) = 0;
	virtual void storeObject(GameObject* obj) = 0;

	

};

#endif

