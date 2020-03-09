#ifndef CENTIPEDEHEADSTATE_H
#define CENTIPEDEHEADSTATE_H
#pragma once
#include "GameObjectState.h"
#include "CentipedeData.h"

class CentipedeHeadState :
	public GameObjectState
{

private:
	CentipedeData* context;

public:
	CentipedeHeadState(CentipedeData* data);
	CentipedeHeadState(const CentipedeHeadState& obj);
	~CentipedeHeadState();
	CentipedeHeadState& operator=(const CentipedeHeadState& obj);

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif
