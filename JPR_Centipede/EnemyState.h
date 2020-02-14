#ifndef ENEMYSTATE_H
#define ENEMYSTATE_H
#include "GameObject.h"
#pragma once

enum class EnemyStateType {EnemyMoveDown, EnemyMoveLeft, EnemyMoveRight, EnemyMoveUp};

class EnemyState
{

public:
	virtual EnemyStateType getState() = 0;
	virtual void checkCollision(GameObject* objs[]) = 0;
	virtual void checkCollision(Window* w) = 0;
	virtual void checkCollision(GameObject* obj) = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif

