#include "EventManager.h"

EventManager::EventManager() {

}

EventManager::~EventManager() {

	for (int i = 0; i < this->events.size(); i++) {

		if (this->events[i] != NULL) {

			delete(this->events[i]);
			this->events[i] = NULL;

		}

	}

}

EventManager* EventManager::getInstance() {

	if (!instance) {

		instance = new EventManager();

	}

	return instance;

}

void EventManager::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

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