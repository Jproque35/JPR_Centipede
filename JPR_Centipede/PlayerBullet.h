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
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

