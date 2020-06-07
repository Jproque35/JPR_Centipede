#ifndef PLAYERBULLETCONTROLLER_H
#define PLAYERBULLETCONTROLLER_H
#pragma once
#include "GameObject.h"

class PlayerBullet :
	public GameObject
{

private:
	PlayerBullet(const PlayerBullet& obj) = delete;
	PlayerBullet& operator=(const PlayerBullet& obj) = delete;

public:
	PlayerBullet(float initX, float initY);
	~PlayerBullet();

	virtual void init(float xPos, float yPos) override;

};

#endif

