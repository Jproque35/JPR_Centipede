#ifndef BULLETCOLLIDEEVENT_H
#define BULLETCOLLIDEVENT_H
#pragma once
#include "GameEvent.h"
#include <vector>

using namespace std;

class GameObjectManager;
class PlayerBullet;

class BulletCollideEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	PlayerBullet* context;
	bool containsHittable(vector<GameObject*> objs);
	bool isHittable(GameObject* obj);

public:
	BulletCollideEvent(PlayerBullet* context);
	BulletCollideEvent(const BulletCollideEvent& obj);
	~BulletCollideEvent();
	BulletCollideEvent& operator=(const BulletCollideEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif

