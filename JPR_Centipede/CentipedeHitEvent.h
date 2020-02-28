#ifndef CENTIPEDEHITEVENT_H
#define CENTIPEDEHITEVENT_H
#pragma once
#include "GameEvent.h"
#include "CentipedeController.h"

class CentipedeHitEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	CentipedeController* context;

public:
	CentipedeHitEvent(GameObjectManager* gm, int i);
	~CentipedeHitEvent();
	void update(float elapsedTime);

};

#endif

