#include "CentipedeMoveRightCommand.h"

CentipedeMoveRightCommand::CentipedeMoveRightCommand(Centipede* context) {

	this->context = context;
	this->initPos = this->context->getPosition();

}

void CentipedeMoveRightCommand::execute(float elapsedTime) {

	Vector2f currPos = this->context->getPosition();

	if (this->initPos.x + 1.0 <= this->context->getPosition().x) {

		currPos.x = this->initPos.x + 1.0;
		this->context->setPosition(currPos);
		this->finished = true;
		cout << "Finished moving right" << endl;

	}
	else {
		currPos.x += this->context->getXVelocity() * elapsedTime;
		this->context->setPosition(currPos);

	}

}