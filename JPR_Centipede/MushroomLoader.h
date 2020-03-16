#ifndef MUSHROOMLOADER_H
#define MUSHROOMLOADER_H
#pragma once
#include "ObjectLoader.h"
#include "Mushroom.h"
#include "MushroomHitEvent.h"
#include <queue>

class MushroomLoader :
	public ObjectLoader
{

private:
	queue<Mushroom*> objs;
	void addEvents(GameObject* obj);

public: 
	MushroomLoader();
	MushroomLoader(const MushroomLoader& obj);
	~MushroomLoader();
	MushroomLoader& operator=(const MushroomLoader& obj);

	GameObject* makeObject(ObjectType type);
	void storeObject(GameObject* obj);

};

#endif

