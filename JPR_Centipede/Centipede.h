#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"
#include <iostream>

class Centipede: public GameObject {

	friend class CentipedeController;
	friend class CentipedeMoveRightCommand;
	friend class CentipedeMoveLeftCommand;
	friend class CentipedeMoveDownCommand;
	friend class CentipedeMoveUpCommand;

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

