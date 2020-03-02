#ifndef BULLETCOLLIDEEVENT_H
#define BULLETCOLLIDEVENT_H
#pragma once
#include "GameEvent.h"
#include "ObjectController.h"
#include "GameObjectManager.h"
#include "PlayerBulletController.h"

class BulletCollideEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	PlayerBulletController* context;

public:
	BulletCollideEvent(GameObjectManager* gm, int i);
	BulletCollideEvent(const BulletCollideEvent& obj);
	~BulletCollideEvent();
	BulletCollideEvent& operator=(const BulletCollideEvent& obj);

	void update(float elapsedTime);

};

#endif

