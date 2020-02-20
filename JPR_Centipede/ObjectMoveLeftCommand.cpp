#include "ObjectMoveLeftCommand.h"

ObjectMoveLeftCommand::ObjectMoveLeftCommand(GameObject* context) {

	this->context = context;

}

void ObjectMoveLeftCommand::execute(float elapsedTime) {

	float moveDist = this->context->xSpeed * elapsedTime;

	if (this->distTravelled + moveDist > 1.0f) {

		float diff = 1.0f - abs(this->distTravelled);
		this->context->position.x -= diff;
		this->finished = true;

	}
	else {

		this->context->position.x -= moveDist;
		this->distTravelled += abs(moveDist);

	}

}