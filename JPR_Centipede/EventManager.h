#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#pragma once
#include "GameEvent.h"
#include "GameObjectManager.h"
#include "CollisionManager.h"
#include <vector>

using namespace std;

class EventManager
{

private:
	GameObjectManager* gm;
	vector<GameEvent*> objectEvents;
	//void updateSub(ObjectController* obj, float elapsedTime);
	//void handleCollision(ObjectController* obj1, ObjectController* obj2);

public:
	EventManager(GameObjectManager* gm);
	void addObjectEvent(int i, GameEvent* event);
	void update(float elapsedTime);

};

#endif

