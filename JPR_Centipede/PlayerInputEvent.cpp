#include "PlayerInputEvent.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "GameObjectState.h"
#include "CommandFactory.h"
#include "CollisionMap.h"
#include "EngineLib.h"

PlayerInputEvent::PlayerInputEvent(Player* context) {

	this->im = InputManager::getInstance();
	this->gm = GameObjectManager::getInstance();
	this->cm = CollisionMap::getInstance();
	this->context = context;

}

PlayerInputEvent::~PlayerInputEvent() {

	//cout << "Destroying PlayerInputEvent..." << endl;

}

inline void PlayerInputEvent::processCollision(GameObject* obj, float xMoveDist, float yMoveDist) {

	//cout << "Checking blocks" << endl;

	FloatRect colBox = this->context->getCollisionBox();
	float xMin = colBox.left;
	float yMin = colBox.top;
	float xMax = colBox.left + colBox.width;
	float yMax = colBox.top + colBox.height;

	if (obj->getCollisionBox().contains(xMin, yMin - yMoveDist)
		|| obj->getCollisionBox().contains(xMax,yMin - yMoveDist)) {

		//cout << "Up is blocked" << endl;

		this->upBlocked = true;

	}
	
	if (obj->getCollisionBox().contains(xMin - xMoveDist, yMin)
		|| obj->getCollisionBox().contains(xMin - xMoveDist, yMax)) {

		this->leftBlocked = true;

	}

	if (obj->getCollisionBox().contains(xMax + xMoveDist, yMin)
		|| obj->getCollisionBox().contains(xMax + xMoveDist, yMax)) {

		this->rightBlocked = true;

	}

	if (obj->getCollisionBox().contains(xMin, yMax + yMoveDist)
		|| obj->getCollisionBox().contains(xMax, yMax + yMoveDist)) {

		this->downBlocked = true;

	}

}

inline void PlayerInputEvent::updateBlockedVars(float xMoveDist, float yMoveDist) {

	vector<GameObject*> objs = EngineLib::getIntersectsObj(this->context);

	for (int i = 0; i < objs.size(); ++i) {

		this->processCollision(objs[i], xMoveDist, yMoveDist);

	}


}

void PlayerInputEvent::update(float elapsedTime) {

	//cout << "Current position is: " << currPos.x << " " << currPos.y << endl;

	if (this->im->isUpPressed()) {

		if (this->context->getY() - 1.0f >= this->cm->getHeight() * 0.6f &&
			!this->cm->containsType(ObjectType::Mushroom, this->context->getX(), this->context->getY() - 1.0f)) {

			this->queueCommand(CommandType::MoveUp);

		}

	}
	else if (this->im->isDownPressed()) {

		if (ceil(this->context->getY()) + 1.0f < this->cm->getHeight() &&
			!this->cm->containsType(ObjectType::Mushroom, this->context->getX(), ceil(this->context->getY()) + 1.0f)) {

			this->queueCommand(CommandType::MoveDown);

		}

	}
	else if (this->im->isLeftPressed()) {

		if (this->context->getX() - 1.0f >= 0 &&
			!this->cm->containsType(ObjectType::Mushroom, this->context->getX() - 1.0f, this->context->getY())) {

			this->queueCommand(CommandType::MoveLeft);

		}

	}
	else if (this->im->isRightPressed()) {

		if (ceil(this->context->getX()) + 1.0f < this->cm->getWidth() &&
			!this->cm->containsType(ObjectType::Mushroom, ceil(this->context->getX()) + 1.0f, this->context->getY())) {

			this->queueCommand(CommandType::MoveRight);

		}
	}

}

inline void PlayerInputEvent::queueCommand(CommandType type) {

	//if (this->context->getState()->getNumCommands() < 1) {
	if(this->context->getCommandsSize() < 1) {
		//this->context->getState()->queueCommand(CommandFactory::makeCommand(type, this->context));
		this->context->addCommand(CommandFactory::makeCommand(type, this->context));

	}

}