#ifndef BULLETCOLLIDEEVENT_H
#define BULLETCOLLIDEVENT_H
#pragma once
#include "GameEvent.h"
#include "PlayerBulletController.h"

class BulletCollideEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	PlayerBulletController* context;

public:
	BulletCollideEvent(GameObjectManager* gm, int i);
	~BulletCollideEvent();
	void update(float elapsedTime);

};

#endif
