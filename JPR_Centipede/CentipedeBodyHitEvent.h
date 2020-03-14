#ifndef CENTIPEDEBODYHITEVENT_H
#define CENTIPEDEBODYHITEVENT_H
#pragma once
#include "GameEvent.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "CentipedeHeadState.h"

class CentipedeBodyHitEvent :
	public GameEventListener
{

private: 
	Centipede* context;

public:
	CentipedeBodyHitEvent(Centipede* context);
	CentipedeBodyHitEvent(const CentipedeBodyHitEvent& obj);
	~CentipedeBodyHitEvent();
	CentipedeBodyHitEvent& operator=(const CentipedeBodyHitEvent& obj);

	void update(float elapsedTime);

};

#endif

