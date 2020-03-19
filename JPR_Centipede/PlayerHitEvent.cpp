#include "PlayerHitEvent.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "ScoreObject.h"

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
		|| gm->hasType(ObjectType::CentipedeHead, xPos, yPos);

}

void PlayerHitEvent::update(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();

	if (this->hasCentipede(this->context->getX(), this->context->getY())) {

		cout << "Player hit by centipede" << endl;
		ScoreManager* sm = ScoreManager::getInstance();

		sm->setLives(sm->getLives() - 1);

	}

}