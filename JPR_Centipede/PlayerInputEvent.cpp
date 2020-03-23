#include "PlayerInputEvent.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "GameObjectState.h"
#include "CommandFactory.h"
#include "CollisionMap.h"

PlayerInputEvent::PlayerInputEvent(Player* context) {

	this->im = InputManager::getInstance();
	this->gm = GameObjectManager::getInstance();
	this->cm = CollisionMap::getInstance();
	this->context = context;

}

PlayerInputEvent::PlayerInputEvent(const PlayerInputEvent& obj) {

	this->gm = obj.gm;
	this->context = obj.context;

}

PlayerInputEvent::~PlayerInputEvent() {

	cout << "Destroying PlayerInputEvent..." << endl;

}

PlayerInputEvent& PlayerInputEvent::operator=(const PlayerInputEvent& obj) {

	return *this;

}
GameEventListener* PlayerInputEvent::recontextCopy(GameObject* obj) {

	return new PlayerInputEvent((Player*)obj);

}

inline void PlayerInputEvent::updateBlockedVars() {




}

void PlayerInputEvent::update(float elapsedTime) {

	this->updateBlockedVars();

	if (this->im->isUpPressed()) {

		if (this->context->getY() - 1.0f >= 0 && !this->upBlocked) {

			this->queueCommand(CommandType::MoveUp);

		}

	}
	else if (this->im->isDownPressed()) {

		if (ceil(this->context->getY()) + 1.0f < this->cm->getHeight()
			&& !this->downBlocked) {

			this->queueCommand(CommandType::MoveDown);

		}

	}
	else if (this->im->isLeftPressed()) {

		if (this->context->getX() - 1.0f >= 0 && !this->leftBlocked) {

			this->queueCommand(CommandType::MoveLeft);

		}

	}
	else if (this->im->isRightPressed()) {

		if (ceil(this->context->getX()) + 1.0f < this->cm->getWidth()
			&& !this->rightBlocked) {

			this->queueCommand(CommandType::MoveRight);
		
		}
	}

}

void PlayerInputEvent::queueCommand(CommandType type) {

	if (this->context->getState()->getNumCommands() < 1) {

		this->context->getState()->queueCommand(CommandFactory::makeCommand(type, this->context));

	}

}