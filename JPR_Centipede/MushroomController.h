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

private:
	Mushroom* context;

public:
	MushroomController(Mushroom* context);
	MushroomController(const MushroomController& obj);
	~MushroomController();
	MushroomController& operator=(const MushroomController& obj);

	GameObject* getData();

};

#endif

