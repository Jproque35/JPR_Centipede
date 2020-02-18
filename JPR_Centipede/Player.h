#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include "GameObject.h"

class Player :
	public GameObject
{

private:
	bool upPressed = false;
	bool downPressed = false;
	bool rightPressed = false;
	bool leftPressed = false;

public:
	Player(float initX, float initY);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void stopUp();
	void stopDown();
	void stopLeft();
	void stopRight();
	void checkCollision(GameObject* obj);
	void checkCollision(float xBoundary, float yBoundary);
	void update(float elapsedTime);

};

#endif

