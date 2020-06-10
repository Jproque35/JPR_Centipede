#ifndef CENTIPEDEHITEVENT_H
#define CENTIPEDEHITEVENT_H
#pragma once
#include "GameEvent.h"
#include <vector>

class GameObjectManager;
class CollisionMap;
class Centipede;
class ScoreManager;

class CentipedeHitEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	CollisionMap* cm;
	Centipede* context;
	ScoreManager* scm;

	CentipedeHitEvent(const CentipedeHitEvent& obj) = delete;
	CentipedeHitEvent& operator=(const CentipedeHitEvent& obj) = delete;

	bool containsBullet(vector<GameObject*> objs);
	void processNext(Centipede& next);

public:
	CentipedeHitEvent(Centipede* context);
	~CentipedeHitEvent();

	void update(float elapsedTime);

};

#endif

