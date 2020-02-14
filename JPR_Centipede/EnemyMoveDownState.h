#ifndef ENEMYMOVEDOWNSTATE_H
#define ENEMYMOVEDOWNSTATE_H
#pragma once
#include "EnemyState.h"
#include "MovingObject.h"

class EnemyMoveDownState : public EnemyState
{

private:
	MovingObject* context;
	void checkCollisionTop(GameObject* obj);

public:
	EnemyMoveDownState(MovingObject* context);
	EnemyStateType getState();
	void checkCollision(GameObject* objs[]);
	void checkCollision(Window* w);
	void checkCollision(GameObject* obj);
	void update(float elapsedTime);

};

#endif

