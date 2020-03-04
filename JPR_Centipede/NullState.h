#ifndef NULLSTATE_H
#define NULLSTATE_H
#pragma once
#include "GameObjectState.h"

class NullState :
	public GameObjectState
{

public:
	NullState();
	NullState(const NullState& obj);
	~NullState();
	NullState& operator=(const NullState& obj);

	void executeEventListeners(vector<GameEventListener*>& events, float elapsedTime);
	void executeCommand(queue<ObjectCommand*>& commands, float elapsedTime);
};

#endif

