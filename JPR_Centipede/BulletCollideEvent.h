#ifndef BULLETCOLLIDEEVENT_H
#define BULLETCOLLIDEVENT_H
#pragma once
#include "GameEvent.h"
#include "GameObject.h"
#include "GameObjectManager.h"
#include "PlayerBullet.h"

class BulletCollideEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	PlayerBullet* context;

public:
	BulletCollideEvent(GameObjectManager* gm, PlayerBullet* context);
	BulletCollideEvent(const BulletCollideEvent& obj);
	~BulletCollideEvent();
	BulletCollideEvent& operator=(const BulletCollideEvent& obj);

	void update(float elapsedTime);

};

#endif

