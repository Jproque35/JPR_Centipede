#ifndef CENTIPEDEHEADSTATE_H
#define CENTIPEDEHEADSTATE_H
#pragma once
#include "CentipedeState.h"

class Centipede;

class CentipedeHeadState :
	public CentipedeState
{

public:
	CentipedeHeadState(Centipede* data);
	CentipedeHeadState(const CentipedeHeadState& obj);
	~CentipedeHeadState();
	CentipedeHeadState& operator=(const CentipedeHeadState& obj);

	void update(float elapsedTime);

};

#endif

