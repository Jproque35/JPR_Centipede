#include "MovingObject.h"

void MovingObject::update(float elapsedTime) {

	this->state->update(elapsedTime);

	this->shape.setPosition(this->position);

}