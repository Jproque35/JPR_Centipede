#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "GameObject.h"
#include "GenericState.h"
#include "MushroomData.h"

class Mushroom :
	public GameObject
{

private:
	MushroomData* context;
	void preUpdate(float elapsedTime);
	void postUpdate(float elapsedTime);

public:
	Mushroom(float initX, float initY);
	Mushroom(const Mushroom& obj);
	~Mushroom();
	Mushroom& operator=(const Mushroom& obj);

	void init(float xPos, float yPos);
	ObjectData* getData() const;

};

#endif

