#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "ObjectData.h"
#include "PlayerBullet.h"
#include "EnemySegment.h"
#include "ObjectState.h"
#include <iostream>

class Enemy: public ObjectData {

protected:
	ObjectState* currState;

public:

	Enemy(float initX, float initY);
	void setNext(EnemySegment* segment);
	void setState(ObjectState* state);
	void checkCollision(ObjectData* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

private:
	float verticalDist = 0.0f;
	float totalDist = 0.0f;
	bool inReverse = false;
	EnemySegment* next = NULL;
	bool isPlayerProjectile(GameObject* obj);

};

#endif

