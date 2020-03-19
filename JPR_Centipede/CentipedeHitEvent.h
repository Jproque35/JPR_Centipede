#ifndef CENTIPEDEHITEVENT_H
#define CENTIPEDEHITEVENT_H
#pragma once
#include "GameEvent.h"

class GameObjectManager;
class Centipede;
class ScoreManager;

class CentipedeHitEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	Centipede* context;
	ScoreManager* scm;

public:
	CentipedeHitEvent(Centipede* context);
	CentipedeHitEvent(const CentipedeHitEvent& obj);
	~CentipedeHitEvent();
	CentipedeHitEvent& operator=(const CentipedeHitEvent& obj);

	void update(float elapsedTime);

};

#endif

