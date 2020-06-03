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
	MushroomNormalState(const MushroomNormalState& obj) = delete;
	MushroomNormalState& operator=(const MushroomNormalState& obj) = delete;

public:
	MushroomNormalState(Mushroom* context);
	~MushroomNormalState();
	virtual void update(float elapsedTime) override;
};

#endif
