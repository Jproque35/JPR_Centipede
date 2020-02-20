#include "ObjectMoveDownCommand.h"

ObjectMoveDownCommand::ObjectMoveDownCommand(GameObject* context) {

	this->context = context;

}

void ObjectMoveDownCommand::execute(float elapsedTime) {

	float moveDist = this->context->ySpeed * elapsedTime;

	if (this->distTravelled + moveDist > 1.0f) {

		float diff = 1.0f - abs(this->distTravelled);
		this->context->position.y += diff;
		this->finished = true;

	}
	else {

		this->context->position.y += moveDist;
		this->distTravelled += abs(moveDist);

	}

}