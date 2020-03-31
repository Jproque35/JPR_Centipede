#ifndef CENTIPEDESTATE_H
#define CENTIEPDESTATE_H
#pragma once
#include "GameObjectState.h"

class Centipede;

class CentipedeState
	: public GameObjectState
{

protected:
	Centipede* context;
	Vector2f lastPos;

public:
	virtual ~CentipedeState();

	virtual void init();

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif
