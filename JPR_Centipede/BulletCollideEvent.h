#ifndef BULLETCOLLIDEEVENT_H
#define BULLETCOLLIDEVENT_H
#pragma once
#include "GameEvent.h"
#include <vector>
#include <SFML/Audio.hpp>

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
	Sound hitSnd;

	BulletCollideEvent(const BulletCollideEvent& obj) = delete;
	BulletCollideEvent& operator=(const BulletCollideEvent& obj) = delete;

public:
	BulletCollideEvent(PlayerBullet* context);
	~BulletCollideEvent();

	void update(float elapsedTime);

};

#endif

