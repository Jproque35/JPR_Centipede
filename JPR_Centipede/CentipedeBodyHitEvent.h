#ifndef CENTIPEDEBODYHITEVENT_H
#define CENTIPEDEBODYHITEVENT_H
#pragma once
#include "GameEvent.h"
#include <vector>

class Centipede;
class CollisionMap;

class CentipedeBodyHitEvent :
	public GameEventListener
{

private: 
	Centipede* context;
	CollisionMap* cm;
	bool containsBullet(vector<GameObject*> objs);

public:
	CentipedeBodyHitEvent(Centipede* context);
	CentipedeBodyHitEvent(const CentipedeBodyHitEvent& obj);
	~CentipedeBodyHitEvent();
	CentipedeBodyHitEvent& operator=(const CentipedeBodyHitEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif

