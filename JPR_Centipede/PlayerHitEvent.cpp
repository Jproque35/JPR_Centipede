#include "PlayerHitEvent.h"

PlayerHitEvent::PlayerHitEvent(Player* context) {

	this->context = context;

}

PlayerHitEvent::PlayerHitEvent(const PlayerHitEvent& obj) {

	this->context = obj.context;

}

PlayerHitEvent::~PlayerHitEvent() {};

PlayerHitEvent& PlayerHitEvent::operator=(const PlayerHitEvent& obj) {

	this->context = obj.context;
	return *this;

}

inline bool PlayerHitEvent::hasCentipede(float xPos, float yPos) {

	GameObjectManager* gm = GameObjectManager::getInstance();

	return gm->hasType(ObjectType::CentipedeBody, xPos, yPos)
		|| gm->hasType(ObjectType::CentipedeData, xPos, yPos);

}

void PlayerHitEvent::update(float elapsedTime) {

	PlayerData* data = (PlayerData*)this->context->getData();
	GameObjectManager* gm = GameObjectManager::getInstance();
	Vector2f currPos = this->context->getData()->getPosition();

	if (this->hasCentipede(currPos.x, currPos.y)) {

		cout << "Player hit by centipede" << endl;

	}

}