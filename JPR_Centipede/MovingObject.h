#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
#pragma once
#include "EnemyState.h"
#include "GameObject.h"
#include "PlayerBullet.h"
#include "MovingSegment.h"
#include <iostream>

class MovingObject: public GameObject {

public:

	MovingObject(float initX, float initY);
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);
	void setPreviousSideState(EnemyStateType prevSideState);
	EnemyStateType getPreviousSideState();

private:
	EnemyState* state = NULL;
	EnemyStateType prevSideState;
	MovingSegment* next;
	float dist = 0.0f;
	bool inReverse = false;
	bool isPlayerProjectile(GameObject* obj);

};

#endif

