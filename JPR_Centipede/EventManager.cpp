#include "EventManager.h"

EventManager::EventManager(GameObjectManager* gm) {

	this->gm = gm;

	cout << "Resizing object events to size " << this->gm->size() << endl;
	this->events.resize(0);
	cout << "Successfully resized" << endl;

}

EventManager::~EventManager() {

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			delete(this->events[i]);
			this->events[i] = NULL;

		}

	}

}

void EventManager::addEvent(GameEventListener* event) {

	this->events.push_back(event);

}

void EventManager::update(float elapsedTime) {

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			this->events[i]->update(elapsedTime);

		}
	}



}

/*
void EventManager::updateSub(ObjectController* obj, float elapsedTime) {

	vector<vector<ObjectController*>> lists = CollisionManager::getGridObjects(obj, this->gm);

	for (int j = 0; j < lists.size(); j++) {

		vector<ObjectController*> currList = lists[j];

		for (int k = 0; k < currList.size(); k++) {

			if (CollisionManager::intersects(obj, currList[k])) {

				handleCollision(obj, currList[k]);

			}

		}

	}

}

void EventManager::handleCollision(ObjectController* obj1, ObjectController* obj2) {

	if (obj1->getData()->getType() == ObjectType::PlayerProjectile
		&& obj2->getData()->getType() == ObjectType::Mushroom) {

		cout << "Mushroom shot" << endl;

	}

}*/