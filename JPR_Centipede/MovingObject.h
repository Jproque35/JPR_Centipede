#pragma once
#include "GameObject.h"
#include "PlayerBullet.h"
#include <iostream>

enum class MovingObjectState {MoveLeft, MoveRight, MoveUp, MoveDown};

class MovingObject: public GameObject {

protected:
	MovingObjectState currState;
	MovingObjectState lastSideState;

public:

	MovingObject(float initX, float initY);
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

private:
	float dist = 0.0f;
	bool inReverse = false;
	bool isPlayerProjectile(GameObject* obj);
	bool collideTopSide(Window* w);
	bool collideBottomSide(Window* w);
	bool collideLeftSide(Window* w);
	bool collideRightSide(Window* w);
	void collideWithObstacle(GameObject* obj);

};

