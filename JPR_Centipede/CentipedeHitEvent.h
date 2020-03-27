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
	bool containsBullet(vector<GameObject*> objs);
	void layMushroom();
	void processNext(Centipede* next);

public:
	CentipedeHitEvent(Centipede* context);
	CentipedeHitEvent(const CentipedeHitEvent& obj);
	~CentipedeHitEvent();
	CentipedeHitEvent& operator=(const CentipedeHitEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif

