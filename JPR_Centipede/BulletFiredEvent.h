#ifndef BULLETFIREDEVENT_H
#define BULLETFIREDEVENT_H
#pragma once
#include "GameEvent.h"

class PlayerBullet;
class GameObjectManager;
class InputManager;

class BulletFiredEvent :
	public GameEventListener
{

private:
	PlayerBullet* context;
	GameObjectManager* gm;
	InputManager* im;

public:
	BulletFiredEvent(PlayerBullet* context);
	BulletFiredEvent(const BulletFiredEvent& obj);
	~BulletFiredEvent();
	BulletFiredEvent& operator=(const BulletFiredEvent& obj);

	void update(float elapsedTime);

};

#endif

