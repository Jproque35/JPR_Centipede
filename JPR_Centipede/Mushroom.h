#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "GameObject.h"
#include "MushroomData.h"

class Mushroom :
	public GameObject
{

protected:	
	void updateSub(float elapsedTime);

private:
	MushroomData* context;

public:
	Mushroom(float initX, float initY);
	Mushroom(const Mushroom& obj);
	~Mushroom();
	Mushroom& operator=(const Mushroom& obj);

	ObjectData* getData();

};

#endif

