#ifndef CENTIPEDEHITEVENT_H
#define CENTIPEDEHITEVENT_H
#pragma once
#include "ObjectController.h"
#include "GameObjectManager.h"
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
	CentipedeHitEvent(const CentipedeHitEvent& obj);
	~CentipedeHitEvent();
	CentipedeHitEvent& operator=(const CentipedeHitEvent& obj);

	void update(float elapsedTime);

};

#endif

