#ifndef ENEMY_H
#define ENEMY_H
#include "MovingObject.h"
#include "EnemyState.h"
#include "Entity.h"
#pragma once

class Enemy : public Entity
{

private:
	EnemyPropertyContainer* obj;
	EnemyState* currState;

public:
	Enemy(float initX, float initY);
	void setState(EnemyState* state);
	void checkCollision(PropertyContainer* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

#endif

