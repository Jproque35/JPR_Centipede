#ifndef ENEMYMOVELEFTSTATE_H
#define ENEMYMOVELEFTSTATE_H
#pragma once
#include "ObjectState.h"
#include "MovingObject.h"

class EnemyMoveLeftState :
	public ObjectState
{

private:
	Enemy* context;

public:
	EnemyMoveLeftState(Enemy* context);
	void checkCollision(ObjectData* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

#endif

