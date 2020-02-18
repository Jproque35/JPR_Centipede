#include "Centipede.h"

void Centipede::update(float elapsedTime) {

	/*
	if (this->currState == MovingObjectState::MoveLeft) {

		this->position.x -= this->xSpeed * elapsedTime;

	}
	else if (this->currState == MovingObjectState::MoveRight) {

		this->position.x += this->xSpeed * elapsedTime;

	}
	else if (this->currState == MovingObjectState::MoveDown) {

		this->position.y += this->ySpeed * elapsedTime;
		this->dist += this->ySpeed * elapsedTime;

		if (this->dist >= 50.0f) {

			this->dist = 0;
			if (this->lastSideState == MovingObjectState::MoveLeft) {

				this->currState = MovingObjectState::MoveRight;

			}
			else if(this->lastSideState == MovingObjectState::MoveRight) {

				this->currState = MovingObjectState::MoveLeft;

			}

		}

	}*/

	this->position.x += this->xSpeed * elapsedTime;
	this->position.y += this->ySpeed * elapsedTime;

	this->shape.setPosition(this->position);

}