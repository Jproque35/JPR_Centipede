#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "GameObject.h"

using namespace sf;

class Mushroom :
	public GameObject
{

private:
	float health = 3.0f;
	bool inHitStun = false;
	bool isPlayerProjectile(GameObject* obj);

public:
	Mushroom(float initX, float initY);
	void checkCollision(GameObject* obj);
	void checkCollision(float xBoundary, float yBoundary);
	void update(float elapsedTime);

};

#endif

