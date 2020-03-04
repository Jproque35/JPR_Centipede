#ifndef GENERICSTATE_H
#define GENERICSTATE_H
#pragma once
#include "GameObjectState.h"

class GenericState :
	public GameObjectState
{

public:
	GenericState();
	GenericState(const GenericState& obj);
	~GenericState();
	GenericState& operator=(const GenericState& obj);

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif

