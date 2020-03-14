#ifndef CENTIPEDEBODYSTATE_H
#define CENTIPEDEBODYSTATE_H
#pragma once
#include "GameObjectState.h"
#include "CentipedeData.h"
#include "Centipede.h"
#include "GameObjectManager.h"

class CentipedeBodyState : 
	public GameObjectState
{

private:
	CentipedeData* context;

public:
	CentipedeBodyState(CentipedeData* data);
	CentipedeBodyState(const CentipedeBodyState& obj);
	~CentipedeBodyState();
	CentipedeBodyState& operator=(const CentipedeBodyState& obj);

	void executeEventListeners(float elapsedTime);
	void executeCommand(float elapsedTime);

};

#endif

