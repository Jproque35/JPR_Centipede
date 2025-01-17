#include "PlayerHitEvent.h"
#include "GameObjectManager.h"
#include "Player.h"
#include "ScoreObject.h"
#include "CollisionMap.h"
#include "ScreenManager.h"
#include "ScoreObject.h"

PlayerHitEvent::PlayerHitEvent(Player* context) {

	this->context = context;

}

PlayerHitEvent::~PlayerHitEvent() {

	//cout << "Destroying PlayerHitEvent..." << endl;

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

		ScreenManager* scnm = ScreenManager::getInstance();

		if(sm->getLives() > 0) {

			scnm->setCurrentScreen(ScreenType::RespawnScreen);

		}
		else {

			sm->setLives(3);
			scnm->setCurrentScreen(ScreenType::RestartScreen);

		}


	}

}