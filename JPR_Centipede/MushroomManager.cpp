#include "MushroomManager.h"
#include "Mushroom.h"
#include "GameObjectManager.h"
#include "CollisionMap.h"
#include "GameObjectFactory.h"

MushroomManager* MushroomManager::instance = NULL;

MushroomManager::MushroomManager() {}

MushroomManager::~MushroomManager() {}

MushroomManager* MushroomManager::getInstance() {

	if (!instance) {

		instance = new MushroomManager();

	}

	return instance;

}

void MushroomManager::resetInstance() {

	if (instance) {

		delete(instance);
		instance = NULL;

	}

}

void MushroomManager::addMushroom(float xPos, float yPos) {

	CollisionMap* cm = CollisionMap::getInstance();
	GameObjectManager* gm = GameObjectManager::getInstance();
	GameObjectFactory* objFactory = GameObjectFactory::getInstance();

	if (!cm->containsType(ObjectType::Mushroom, xPos, yPos)) {

		GameObject* newObj = objFactory->makeObject(ObjectType::Mushroom, xPos, yPos);

		gm->add( newObj );
		newObj->init(xPos, yPos);
		++this->numActive;

	}

}

int MushroomManager::getNumActive() const {

	return this->numActive;

}