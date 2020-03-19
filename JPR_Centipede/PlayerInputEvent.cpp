#include "PlayerInputEvent.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "GameObjectState.h"
#include "CommandFactory.h"

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

	//cout << "Current position is: " << currPos.x << " " << currPos.y << endl;

	if (this->im->isUpPressed()) {

		if (this->context->getY() - 1.0f >= 0 &&
			!this->gm->hasType(ObjectType::Mushroom, this->context->getX(), this->context->getY() - 1.0f)) {

			this->queueCommand(CommandType::MoveUp);

		}

	}
	else if (this->im->isDownPressed()) {

		if (ceil(this->context->getY()) + 1.0f < this->gm->getGridHeight() &&
			!this->gm->hasType(ObjectType::Mushroom, this->context->getX(), ceil(this->context->getY()) + 1.0f)) {

			this->queueCommand(CommandType::MoveDown);

		}

	}
	else if (this->im->isLeftPressed()) {

		if (this->context->getX() - 1.0f >= 0 &&
			!this->gm->hasType(ObjectType::Mushroom, this->context->getX() - 1.0f, this->context->getY())) {

			this->queueCommand(CommandType::MoveLeft);

		}

	}
	else if (this->im->isRightPressed()) {

		if (ceil(this->context->getX()) + 1.0f < this->gm->getGridWidth() &&
			!this->gm->hasType(ObjectType::Mushroom, ceil(this->context->getX()) + 1.0f, this->context->getY())) {

			this->queueCommand(CommandType::MoveRight);
		
		}
	}

}

void PlayerInputEvent::queueCommand(CommandType type) {

	if (this->context->getState()->getNumCommands() < 1) {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(type, this->context));

	}

}