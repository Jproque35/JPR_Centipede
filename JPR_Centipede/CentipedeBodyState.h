#ifndef CENTIPEDEBODYSTATE_H
#define CENTIPEDEBODYSTATE_H
#pragma once
#include "GameObjectState.h"

class Centipede;

class CentipedeBodyState : 
	public GameObjectState
{

private:
	Centipede* context;
	Vector2f lastPos;

public:
	CentipedeBodyState(Centipede* data);
	CentipedeBodyState(const CentipedeBodyState& obj);
	~CentipedeBodyState();
	CentipedeBodyState& operator=(const CentipedeBodyState& obj);

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif

