#ifndef BULLETFIREDEVENT_H
#define BULLETFIREDEVENT_H
#pragma once
#include "GameEvent.h"
#include "PlayerBulletController.h"

class BulletFiredEvent :
	public GameEventListener
{

private:
	PlayerBulletController* context;
	GameObjectManager* gm;

public:
	BulletFiredEvent(GameObjectManager* gm, int i);
	BulletFiredEvent(const BulletFiredEvent& obj);
	~BulletFiredEvent();
	BulletFiredEvent& operator=(const BulletFiredEvent& obj);

	void update(float elapsedTime);

};

#endif

