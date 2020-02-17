#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H
#pragma once
#include "ObjectData.h"

class PlayerBullet : public ObjectData
{

private:
	float distanceTravelled = 0;

public:
	PlayerBullet(float initX, float initY);
	void setPosition(float x, float Y);
	float getDistanceTravelled();
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

#endif

