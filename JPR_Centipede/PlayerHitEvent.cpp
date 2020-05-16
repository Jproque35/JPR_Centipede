#include "PlayerHitEvent.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "ScoreObject.h"
#include "CollisionMap.h"
#include "ScreenManager.h"

PlayerHitEvent::PlayerHitEvent(Player* context) {

	this->context = context;

}

PlayerHitEvent::PlayerHitEvent(const PlayerHitEvent& obj) {

	this->context = obj.context;

}

PlayerHitEvent::~PlayerHitEvent() {

	//cout << "Destroying PlayerHitEvent..." << endl;

}

PlayerHitEvent& PlayerHitEvent::operator=(const PlayerHitEvent& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

GameEventListener* PlayerHitEvent::recontextCopy(GameObject* obj) {

	return new PlayerHitEvent((Player*)obj);

}

inline bool PlayerHitEvent::isCentipede(GameObject* obj) {

	return obj->getType() == ObjectType::CentipedeHead
		|| obj->getType() == ObjectType::CentipedeBody;

}

bool PlayerHitEvent::intersectsCentipede() {

	CollisionMap* cm = CollisionMap::getInstance();
	FloatRect colBox = this->context->getCollisionBox();
	int xStart = floor(colBox.left);
	int yStart = floor(colBox.top);
	int xEnd = floor(colBox.left + colBox.width);
	int yEnd = floor(colBox.top + colBox.height);

	vector<GameObject*> currList;
	for (int i = xStart; i <= xEnd; ++i) {

		for (int j = yStart; j <= yEnd; ++j) {

			currList = cm->get(i, j);

			for (int k = 0; k < currList.size(); ++k) {

				if (currList[k]->getCollisionBox().intersects(colBox)
					&& this->isCentipede(currList[k])) {

					return true;

				}

			}

		}

	}

	return false;

}

void PlayerHitEvent::update(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();

	if (this->intersectsCentipede()) {

		cout << "Player hit by centipede" << endl;
		ScoreManager* sm = ScoreManager::getInstance();

		sm->setLives(sm->getLives() - 1);

		//ScreenManager* const scnm = ScreenManager::getInstance();
		//scnm->setCurrentScreen(ScreenType::RespawnScreen);


	}

}