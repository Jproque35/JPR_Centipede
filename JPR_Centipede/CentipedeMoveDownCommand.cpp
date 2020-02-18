#include "CentipedeMoveDownCommand.h"

CentipedeMoveDownCommand::CentipedeMoveDownCommand(Centipede* context) {

	this->context = context;
	this->initPos = this->context->getPosition();

}

void CentipedeMoveDownCommand::execute(float elapsedTime) {

	Vector2f currPos = this->context->getPosition();

	if (this->initPos.y + 1.0 <= this->context->getPosition().y) {

		currPos.y = this->initPos.y + 1.0;
		this->context->setPosition(currPos);
		this->finished = true;
		cout << "Finished moving down" << endl;

	}
	else {
		currPos.y += this->context->getYVelocity() * elapsedTime;
		this->context->setPosition(currPos);

	}

}