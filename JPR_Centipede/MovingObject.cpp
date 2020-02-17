#include "MovingObject.h"


Enemy::Enemy(float initX, float initY) :ObjectData(initX, initY) {

	this->xSpeed = 400.0f;
	this->ySpeed = 400.0f;
	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->type = ObjectType::MovingObject;
	this->currState = NULL;
	this->inReverse = false;

}

void Enemy::setNext(EnemySegment* segment) {

	this->next = segment;

}

void Enemy::setState(ObjectState* state) {

	this->currState = state;

}

