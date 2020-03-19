#ifndef MUSHROOMNORMALSTATE_H
#define MUSHROOMNORMALSTATE_H
#pragma once
#include "GenericState.h"
#include "GameObjectState.h"

class Mushroom;

class MushroomNormalState 
	: public GenericState {

private:
	Mushroom* context = NULL;

public:
	MushroomNormalState(Mushroom* context);
	MushroomNormalState(const MushroomNormalState& obj);
	~MushroomNormalState();
	MushroomNormalState& operator=(const MushroomNormalState& obj);

};

#endif
