#ifndef CENTIPEDEHEADSTATE_H
#define CENTIPEDEHEADSTATE_H
#pragma once
#include "GameObjectState.h"

class Centipede;

class CentipedeHeadState :
	public GameObjectState
{

private:
	Centipede* context;
	Vector2f lastPos;

public:
	CentipedeHeadState(Centipede* data);
	CentipedeHeadState(const CentipedeHeadState& obj);
	~CentipedeHeadState();
	CentipedeHeadState& operator=(const CentipedeHeadState& obj);

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif

