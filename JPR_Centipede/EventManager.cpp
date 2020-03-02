#include "EventManager.h"

EventManager::EventManager(GameObjectManager* gm) {

	this->gm = gm;

	cout << "Resizing object events to size " << this->gm->size() << endl;
	this->events.resize(0);
	cout << "Successfully resized" << endl;

}

EventManager::EventManager(const EventManager& obj) {

	this->gm = gm;
	this->events = events;

}

EventManager::~EventManager() {

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			delete(this->events[i]);
			this->events[i] = NULL;

		}

	}

}

EventManager& EventManager::operator=(const EventManager& obj) {

	return *this;

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