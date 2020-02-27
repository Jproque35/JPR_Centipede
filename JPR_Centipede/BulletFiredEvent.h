#ifndef BULLETFIREDEVENT_H
#define BULLETFIREDEVENT_H
#pragma once
#include "GameEvent.h"
#include "PlayerBulletController.h"

class BulletFiredEvent :
	public GameEvent
{

private:
	PlayerBulletController* context;
	GameObjectManager* gm;

public:
	BulletFiredEvent(GameObjectManager* gm, int i);
	~BulletFiredEvent();
	void update(float elapsedTime);

};

#endif

