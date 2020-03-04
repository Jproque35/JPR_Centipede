#ifndef GENERICSTATE_H
#define GENERICSTATE_H
#pragma once
#include "GameObjectState.h"

class GenericState :
	public GameObjectState
{

public:
	void executeEventListeners(vector<GameEventListener*>& events, float elapsedTime);
	void executeCommand(queue<ObjectCommand*>& commands, float elapsedTime);

};

#endif

