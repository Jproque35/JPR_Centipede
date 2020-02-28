#ifndef MUSHROOMCONTROLLER_H
#define MUSHROOMCONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "Mushroom.h"

class MushroomController :
	public ObjectController
{

protected:	
	void updateSub(float elapsedTime);
	void collisionSub(GameObject* obj);

private:
	Mushroom* context;

public:
	MushroomController(Mushroom* context);
	~MushroomController();
	GameObject* getData();

};

#endif

