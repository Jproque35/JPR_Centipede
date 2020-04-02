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

private:
	void processNext(ObjectCommand* currCommand);

public:
	virtual ~CentipedeState();

	void init();

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif
