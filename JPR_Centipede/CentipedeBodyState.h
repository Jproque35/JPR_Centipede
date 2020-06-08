#ifndef CENTIPEDEBODYSTATE_H
#define CENTIPEDEBODYSTATE_H
#pragma once
#include "CentipedeState.h"

class Centipede;

class CentipedeBodyState : 
	public CentipedeState
{

private:
	CentipedeBodyState(const CentipedeBodyState& obj) = delete;
	CentipedeBodyState& operator=(const CentipedeBodyState& obj) = delete;

public:
	CentipedeBodyState(Centipede* data);
	virtual ~CentipedeBodyState();

	void update(float elapsedTime);

};

#endif

