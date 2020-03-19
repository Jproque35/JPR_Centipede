#ifndef PLAYERBULLETCONTROLLER_H
#define PLAYERBULLETCONTROLLER_H
#pragma once
#include "GameObject.h"

class PlayerBullet :
	public GameObject
{

public:
	PlayerBullet(float initX, float initY);
	PlayerBullet(const PlayerBullet& obj);
	~PlayerBullet();
	PlayerBullet& operator=(const PlayerBullet& obj);

	void init(float xPos, float yPos);

};

#endif

