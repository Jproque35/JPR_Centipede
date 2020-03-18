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
	float distTravelled = 0.0f;

protected:


public:
	PlayerBullet(float initX, float initY);
	PlayerBullet(const PlayerBullet& obj);
	~PlayerBullet();
	PlayerBullet& operator=(const PlayerBullet& obj);

	void init(float xPos, float yPos);
	ObjectData* getData() const;
	void update(float elapsedTime);

};

#endif

