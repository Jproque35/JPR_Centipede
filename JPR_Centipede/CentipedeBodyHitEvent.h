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
	CollisionMap* cm = NULL;


	CentipedeBodyHitEvent(const CentipedeBodyHitEvent& obj) = delete;
	CentipedeBodyHitEvent& operator=(const CentipedeBodyHitEvent& obj) = delete;

	bool containsBullet(vector<GameObject*> objs);
	void changeContextToHead(float hitX, float hitY);
	void reverseContextDirection();

public:
	CentipedeBodyHitEvent(Centipede* context);
	~CentipedeBodyHitEvent();

	void update(float elapsedTime);

};

#endif

