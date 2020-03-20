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
	this->sBuf = sdm->get(0);
	this->bulletSound.setBuffer(this->sBuf);

}

FirePressedEvent::FirePressedEvent(const FirePressedEvent& obj) {}

FirePressedEvent::~FirePressedEvent() {}

FirePressedEvent& FirePressedEvent::operator=(const FirePressedEvent& obj) {

	return *this;

}

void FirePressedEvent::update(float elapsedTime) {

	GameObjectManager* gm = GameObjectManager::getInstance();
	GameObjectFactory* objFactory = GameObjectFactory::getInstance();
	InputManager* im = InputManager::getInstance();

	if (im->isFirePressed()) {


		Player* player = (Player*)gm->get(0);
		PlayerBullet* bullet = (PlayerBullet*)objFactory->makeObject(ObjectType::PlayerBullet, 0.0f, 0.0f);

		cout << bullet << endl;

		if (bullet != NULL) {
			gm->add(bullet);
			bullet->init(player->getX(), player->getY());
			this->bulletSound.play();
		}

	}

}