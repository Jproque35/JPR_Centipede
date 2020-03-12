#ifndef CENTIPEDEHITEVENT_H
#define CENTIPEDEHITEVENT_H
#pragma once
#include "GameObject.h"
#include "GameEvent.h"
#include "GameObjectManager.h"
#include "Centipede.h"

class CentipedeHitEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	Centipede* context;
	ScoreManager* sm;

public:
	CentipedeHitEvent(Centipede* context);
	CentipedeHitEvent(const CentipedeHitEvent& obj);
	~CentipedeHitEvent();
	CentipedeHitEvent& operator=(const CentipedeHitEvent& obj);

	void update(float elapsedTime);

};

#endif

