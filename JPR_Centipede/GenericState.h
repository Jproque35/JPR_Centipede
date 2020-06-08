#ifndef GENERICSTATE_H
#define GENERICSTATE_H
#pragma once
#include "GameObjectState.h"

class GenericState :
	public GameObjectState
{

private:
	//states are unique per object
	GenericState(const GenericState& obj) = delete;

	//states are unique per object
	GenericState& operator=(const GenericState& obj) = delete;

public:
	GenericState();
	virtual ~GenericState();

	void executeEventListeners(float elapsedTime);
	/*
	void update(float elapsedTime);*/

};

#endif

