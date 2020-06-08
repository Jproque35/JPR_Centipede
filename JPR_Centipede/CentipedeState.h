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

private:
	CentipedeState(const CentipedeState& obj) = delete;
	CentipedeState& operator=(const CentipedeState& obj) = delete;

public:
	CentipedeState(Centipede* obj);
	virtual ~CentipedeState();

	void init();

	void executeEventListeners(float elapsedTime);

};

#endif
