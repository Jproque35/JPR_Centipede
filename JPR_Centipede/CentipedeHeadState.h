#ifndef CENTIPEDEHEADSTATE_H
#define CENTIPEDEHEADSTATE_H
#pragma once
#include "CentipedeState.h"

class Centipede;

class CentipedeHeadState :
	public CentipedeState
{

private:
	CentipedeHeadState(const CentipedeHeadState& obj) = delete;
	CentipedeHeadState& operator=(const CentipedeHeadState& obj) = delete;

public:
	CentipedeHeadState(Centipede* data);
	virtual ~CentipedeHeadState();

	void update(float elapsedTime);

};

#endif

