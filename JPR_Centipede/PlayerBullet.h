#ifndef PLAYERBULLETCONTROLLER_H
#define PLAYERBULLETCONTROLLER_H
#pragma once
#include "GameObject.h"
#include "GenericState.h"
#include "PlayerBulletData.h"
#include "PlayerBulletFireCommand.h"

class PlayerBullet :
	public GameObject
{

private:
	PlayerBulletData* context;

protected:
	void preUpdate(float elapsedTime);
	void postUpdate(float elapsedTime);

public:
	PlayerBullet(float initX, float initY);
	PlayerBullet(const PlayerBullet& obj);
	~PlayerBullet();
	PlayerBullet& operator=(const PlayerBullet& obj);

	ObjectData* getData() const;

};

#endif

