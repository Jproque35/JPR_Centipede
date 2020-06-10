#ifndef MUSHROOMHITEVENT_H
#define MUSHROOMHITEVENT_H
#pragma once
#include "GameEvent.h"
#include <vector>

using namespace std;

class Mushroom;
class GameObjectManager;

class MushroomHitEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	Mushroom* context;

	MushroomHitEvent(const MushroomHitEvent& obj) = delete;
	MushroomHitEvent& operator=(const MushroomHitEvent& obj) = delete;

	bool containsBullet(vector<GameObject*> objs);
	void handleHit();

public:
	MushroomHitEvent(Mushroom* context);
	~MushroomHitEvent();

	void update(float elapsedTime);

};

#endif

