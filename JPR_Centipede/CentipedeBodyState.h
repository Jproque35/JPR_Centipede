#ifndef CENTIPEDEBODYSTATE_H
#define CENTIPEDEBODYSTATE_H
#pragma once
#include "CentipedeState.h"

class Centipede;

class CentipedeBodyState : 
	public CentipedeState
{

public:
	CentipedeBodyState(Centipede* data);
	CentipedeBodyState(const CentipedeBodyState& obj);
	~CentipedeBodyState();
	CentipedeBodyState& operator=(const CentipedeBodyState& obj);

	void update(float elapsedTime);

};

#endif

