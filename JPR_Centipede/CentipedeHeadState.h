#ifndef CENTIPEDEHEADSTATE_H
#define CENTIPEDEHEADSTATE_H
#pragma once
#include "GameObjectState.h"

class CentipedeHeadState :
	public GameObjectState
{

public:
	void executeEventListeners(vector<GameEventListener*>& events, float elapsedTime);
	void executeCommand(queue<ObjectCommand*>& commands, float elapsedTime);

};

#endif

