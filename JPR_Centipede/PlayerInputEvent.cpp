#include "PlayerInputEvent.h"

PlayerInputEvent::PlayerInputEvent(Player* context) {

	this->im = InputManager::getInstance();
	this->gm = GameObjectManager::getInstance();
	this->context = context;

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

	if (this->im->isUpPressed()) {

		if (currPos.y - 1.0f >= 0 &&
			!this->gm->hasType(ObjectType::MushroomData, currPos.x, currPos.y - 1.0f)) {

			this->queueCommand(CommandType::MoveUp);

		}

	}
	else if (this->im->isDownPressed()) {

		if (ceil(currPos.y) + 1.0f < this->gm->getGridHeight() &&
			!this->gm->hasType(ObjectType::MushroomData, currPos.x, ceil(currPos.y) + 1.0f)) {

			this->queueCommand(CommandType::MoveDown);

		}

	}
	else if (this->im->isLeftPressed()) {

		if (currPos.x - 1.0f >= 0 &&
			!this->gm->hasType(ObjectType::MushroomData, currPos.x - 1.0f, currPos.y)) {

			this->queueCommand(CommandType::MoveLeft);

		}

	}
	else if (this->im->isRightPressed()) {

		if (ceil(currPos.x) + 1.0f < this->gm->getGridWidth() &&
			!this->gm->hasType(ObjectType::MushroomData, ceil(currPos.x) + 1.0f, currPos.y)) {

			this->queueCommand(CommandType::MoveRight);
		
		}
	}

}

void PlayerInputEvent::queueCommand(CommandType type) {

	if (this->context->commandQueueSize() < 1) {

		this->context->queueCommand(CommandFactory::makeCommand(type, this->context->getData()));

	}

}