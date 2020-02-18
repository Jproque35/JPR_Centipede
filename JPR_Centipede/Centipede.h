#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"
#include <iostream>

class Centipede: public GameObject {

public:

	Centipede(float initX, float initY);
	void checkCollision(GameObject* obj);
	void checkCollision(float xBoundary, float yBoundary);
	void update(float elapsedTime);

private:
	float dist = 0.0f;
	bool isPlayerProjectile(GameObject* obj);

};

#endif

