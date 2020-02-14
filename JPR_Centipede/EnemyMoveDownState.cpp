#include "EnemyMoveDownState.h"

EnemyMoveDownState::EnemyMoveDownState(MovingObject* context) {

	this->context = context;

}

EnemyStateType EnemyMoveDownState::getState() {

	return EnemyStateType::EnemyMoveDown;

}

void EnemyMoveDownState::checkCollision(GameObject* objs[]) {



}

void EnemyMoveDownState::checkCollision(Window* w) {



}

void EnemyMoveDownState::checkCollision(GameObject* obj) {

	if (obj->getType() == ObjectType::DestroyableObject) {

		this->checkCollisionTop(obj);

	}

}

void EnemyMoveDownState::checkCollisionTop(GameObject* obj) {

	FloatRect* colBox1 = &(this->context->getCollisionBox());
	FloatRect* colBox2 = &(obj->getCollisionBox());

	if (colBox1->intersects(*colBox2)) {

		if (colBox1->top + 50.0f > colBox2->top) {



		}

	}

}

void EnemyMoveDownState::update(float elapsedTime) {

	Vector2f* currPos = &(this->context->getPosition());
	currPos->y += this->context->getYVelocity();

}