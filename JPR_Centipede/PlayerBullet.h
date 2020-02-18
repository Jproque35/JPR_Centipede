#ifndef BULLET_H
#define BULLET_H
#pragma once
#include "GameObject.h"

class PlayerBullet : public GameObject
{

private:
	float distanceTravelled = 0;

public:
	PlayerBullet(float initX, float initY);
	void setPosition(float x, float Y);
	float getDistanceTravelled();
	void checkCollision(GameObject* obj);
	void checkCollision(float xBoundary, float yBoundary);
	void update(float elapsedTime);

};

#endif

