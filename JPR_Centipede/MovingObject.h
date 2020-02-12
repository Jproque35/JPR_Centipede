#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"

class MovingObject: public GameObject {

public:

	MovingObject(float initX, float initY);
	void collideWithTopOrBottom();
	void collideWithLeftOrRight();
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

private:
	float dist = 0.0f;
	bool isPlayerProjectile(GameObject* obj);

};

