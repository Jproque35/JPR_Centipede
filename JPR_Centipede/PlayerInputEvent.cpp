#include "PlayerInputEvent.h"

PlayerInputEvent::PlayerInputEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (PlayerController*)(gm->get(i));

}

PlayerInputEvent::PlayerInputEvent(const PlayerInputEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

PlayerInputEvent::~PlayerInputEvent() {}

PlayerInputEvent& PlayerInputEvent::operator=(const PlayerInputEvent& obj) {

	return *this;

}

void PlayerInputEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();

	//cout << "Current position is: " << currPos.x << " " << currPos.y << endl;

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		if (currPos.y - 1.0f >= 0 &&
			!this->gm->hasType(ObjectType::Mushroom, currPos.x, currPos.y - 1.0f)) {

			this->queueCommand(CommandType::MoveUp);

		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {

		if (ceil(currPos.y) + 1.0f < this->gm->getGridHeight() &&
			!this->gm->hasType(ObjectType::Mushroom, currPos.x, ceil(currPos.y) + 1.0f)) {

			this->queueCommand(CommandType::MoveDown);

		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {

		if (currPos.x - 1.0f >= 0 &&
			!this->gm->hasType(ObjectType::Mushroom, currPos.x - 1.0f, currPos.y)) {

			this->queueCommand(CommandType::MoveLeft);

		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {

		if (ceil(currPos.x) + 1.0f < this->gm->getGridWidth() &&
			!this->gm->hasType(ObjectType::Mushroom, ceil(currPos.x) + 1.0f, currPos.y)) {

			this->queueCommand(CommandType::MoveRight);
		
		}
	}

}

void PlayerInputEvent::queueCommand(CommandType type) {

	if (this->context->commandQueueSize() < 1) {

		this->context->queueCommand(CommandFactory::makeCommand(type, this->context->getData()));

	}

}