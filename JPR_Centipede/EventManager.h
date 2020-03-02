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
	vector<GameEventListener*> events;

public:
	EventManager(GameObjectManager* gm);
	EventManager(const EventManager& obj);
	~EventManager();
	EventManager& operator=(const EventManager& obj);

	void addEvent(GameEventListener* event);
	void update(float elapsedTime);

};

#endif

