#ifndef CENTIPEDEBODYHITEVENT_H
#define CENTIPEDEBODYHITEVENT_H
#pragma once
#include "GameEvent.h"
#include <vector>

class Centipede;
class CollisionMap;
class ScoreManager;
class GameObjectManager;

class CentipedeBodyHitEvent :
	public GameEventListener
{

private: 
	Centipede* context;
	ScoreManager* scm = NULL;
	GameObjectManager* gm = NULL;
	CollisionMap* cm = NULL;;
	bool containsBullet(vector<GameObject*> objs);
	void layMushroom(float hitX, float hitY);
	void changeContextToHead(float hitX, float hitY);
	void reverseContextDirection();

public:
	CentipedeBodyHitEvent(Centipede* context);
	CentipedeBodyHitEvent(const CentipedeBodyHitEvent& obj);
	~CentipedeBodyHitEvent();
	CentipedeBodyHitEvent& operator=(const CentipedeBodyHitEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif

