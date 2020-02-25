#include "EventManager.h"

EventManager::EventManager(GameObjectManager* gm) {

	this->gm = gm;

	cout << "Resizing object events to size " << this->gm->size() << endl;
	this->objectEvents.resize(this->gm->size());
	cout << "Successfully resized" << endl;

	for (int i = 0; i < this->objectEvents.size(); i++) {

		//this->objectEvents[i] = NULL;
		cout << "Position " << i << " set to null" << endl;

	}

}

void EventManager::addObjectEvent(int i, GameEvent* event) {

	this->objectEvents[i] = event;

}

void EventManager::update(float elapsedTime) {

	/*
	for (int i = 0; i < gm->size(); i++) {

		this->updateSub(this->gm->get(i), elapsedTime);


	}*/

	for (int i = 0; i < this->objectEvents.size(); i++) {

		if (this->objectEvents[i] != NULL) {

			this->objectEvents[i]->update(elapsedTime);

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