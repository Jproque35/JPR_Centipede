#include "MoveHorizontalState.h"


MovingHorizontalState::MovingHorizontalState(MovingObject* obj) :MovingObjectState(obj) {



}

void MovingHorizontalState::checkCollision(GameObject* objs[]) {



}

void MovingHorizontalState::checkCollision(GameObject* obj) {



}

void MovingHorizontalState::checkCollision(Window* w) {



}
void MovingHorizontalState::update(float elapsedTime) {

	Vector2f objPos = this->obj->getPosition();
	objPos.x += this->obj->getXVelocity();

}