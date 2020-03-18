#include "Player.h"

Player::Player(float initX, float initY) {

	this->context = new PlayerData(initX, initY);
	this->state = new GenericState();
	this->init(initX, initY);

}

Player::Player(const Player& obj) {

	this->context = obj.context;

}

Player::~Player() {

	this->clearCommands();

	if (this->context != NULL) {

		delete(this->context);
		this->context = NULL;

	}

}

void Player::init(float xPos, float yPos) {

	this->context->init(xPos, yPos);

}

ObjectData* Player::getData() const {

	return this->context;

}

void Player::updateCollisions() {

	vector<GameObject*> objs = CollisionManager::getGridObjects(this);

	this->upBlocked = false;
	this->downBlocked = false;
	this->leftBlocked = false;
	this->rightBlocked = false;

	for (int i = 0; i < objs.size(); i++) {

		if (CollisionManager::intersects(this, objs[i])) {

			if (objs[i]->getData()->getPosition().x < this->context->getPosition().x) {

				this->upBlocked = true;

			}



		}

	}

}

void Player::update(float elapsedTime) {

	/*
	this->updateCollisions();

	InputManager* im = InputManager::getInstance();
	GameObjectManager* gm = GameObjectManager::getInstance();
	Vector2f currPos = this->context->getPosition();
	float speed = this->context->getXVelocity();

	if (im->isUpPressed()) {

		if (currPos.y - 1.0f >= 0 &&
			!gm->hasType(ObjectType::MushroomData, currPos.x, currPos.y - 1.0f)) {

			this->queueStateCommand(CommandType::MoveUp);

		}

	}
	else if (im->isDownPressed()) {

		if (ceil(currPos.y) + 1.0f < gm->getGridHeight() &&
			!gm->hasType(ObjectType::MushroomData, currPos.x, ceil(currPos.y) + 1.0f)) {

			this->queueStateCommand(CommandType::MoveDown);

		}

	}
	else if (im->isLeftPressed()) {

		if (currPos.x - 1.0f >= 0 &&
			!gm->hasType(ObjectType::MushroomData, currPos.x - 1.0f, currPos.y)) {

			this->queueStateCommand(CommandType::MoveLeft);

		}

	}
	else if (im->isRightPressed()) {

		if (ceil(currPos.x) + 1.0f < gm->getGridWidth() &&
			!gm->hasType(ObjectType::MushroomData, ceil(currPos.x) + 1.0f, currPos.y)) {

			this->queueStateCommand(CommandType::MoveRight);

		}
	}*/
	this->state->executeCommand(elapsedTime);

}

void Player::queueStateCommand(CommandType type) {

	if (this->state->getCommandQueueSize() < 1) {

		this->state->queueCommand(CommandFactory::makeCommand(type, this->context));

	}

}