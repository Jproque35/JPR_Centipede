#include "MovingObject.h"

void Enemy::update(float elapsedTime) {

	if (this->currState != NULL) {

		this->currState->update(elapsedTime);

	}

	this->shape.setPosition(this->position);

}