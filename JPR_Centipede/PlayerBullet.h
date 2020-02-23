#ifndef BULLET_H
#define BULLET_H
#pragma once
#include "GameObject.h"

class PlayerBullet : public GameObject
{

	friend class PlayerBulletFireCommand;

public:
	PlayerBullet(float initX, float initY);

};

#endif

