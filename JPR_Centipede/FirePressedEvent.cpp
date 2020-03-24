#include "FirePressedEvent.h"
#include "InputManager.h"
#include "GameObjectManager.h"
#include "GameObjectFactory.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "ObjectType.h"
#include "SoundManager.h"

FirePressedEvent::FirePressedEvent() {

	SoundManager* sdm = SoundManager::getInstance();
	this->bulletSound.setBuffer(*sdm->get(0));

}

FirePressedEvent::FirePressedEvent(const FirePressedEvent& obj) {}

FirePressedEvent::~FirePressedEvent() {}

FirePressedEvent& FirePressedEvent::operator=(const FirePressedEvent& obj) {

	return *this;

}

GameEventListener* FirePressedEvent::recontextCopy(GameObject* obj) {

	return new FirePressedEvent();

}

void FirePressedEvent::update(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();
	GameObjectFactory* objFactory = GameObjectFactory::getInstance();
	InputManager* im = InputManager::getInstance();

	if (im->isFirePressed()) {

		Player* player = (Player*)gm->getPlayerObject();
		PlayerBullet* bullet = (PlayerBullet*)objFactory->makeObject(ObjectType::PlayerBullet, 0.0f, 0.0f);

		cout << bullet << endl;

		if (bullet != NULL) {

			gm->add(bullet);
			bullet->init(player->getX(), player->getY());
			this->bulletSound.play();

		}

	}

}