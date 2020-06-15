#include "CentipedeManager.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "GameObjectFactory.h"

CentipedeManager* CentipedeManager::instance = NULL;

CentipedeManager::CentipedeManager() {

	this->objFactory = GameObjectFactory::getInstance();

	for (int i = 0; i < 20; ++i) {

		this->centipedes.push(new Centipede());

	}

}

CentipedeManager::~CentipedeManager() {

	Centipede* currObj = NULL;

	while (this->centipedes.size() > 0) {

		currObj = this->centipedes.front();
		this->centipedes.pop();
		delete(currObj);
		currObj = NULL;

	}

}

CentipedeManager* CentipedeManager::getInstance() {

	if (!instance) {

		instance = new CentipedeManager();

	}

	return instance;

}

void CentipedeManager::resetInstance() {

	delete(instance);
	instance = NULL;

}

int CentipedeManager::getNumActive() const {

	return this->currActive;

}

void CentipedeManager::setNumActive(int i) {

	this->currActive = i;

}

int CentipedeManager::getMaxActive() const {

	return this->maxActive;

}

Centipede* CentipedeManager::makeHead() {

	if (this->centipedes.size() > 0) {

		Centipede* desire = this->centipedes.front();
		desire->setStateType(StateType::CentipedeHeadState);
		this->centipedes.pop();
		return desire;

	}
	else {

		return NULL;

	}

}

Centipede* CentipedeManager::makeBody() {

	if (this->centipedes.size() > 0) {

		Centipede* desire = this->centipedes.front();
		desire->setStateType(StateType::CentipedeBodyState);
		this->centipedes.pop();
		return desire;

	}
	else {

		return NULL;

	}

}

vector<Centipede*> CentipedeManager::add(int length) {

	GameObjectManager* gm = GameObjectManager::getInstance();
	vector<Centipede*> centi;

	if (length > 0) {

		Centipede* currObj = this->makeHead();

		gm->add(currObj);
		centi.push_back(currObj);

		for (int i = 0; i < length - 1; ++i) {

			currObj = this->makeBody();
			gm->add(currObj);
			centi.push_back(currObj);

		}

		for (int i = 0; i < length - 1; ++i) {

			centi[i]->setNext(centi[i + 1]);

		}

		for (int i = length - 1; i > 0; --i) {

			centi[i]->setPrev(centi[i - 1]);

		}

		this->currActive += length;

	}

	return centi;

}

void CentipedeManager::remove(int i) {

	GameObjectManager* gm = GameObjectManager::getInstance();

	if (dynamic_cast<Centipede*>(gm->get(i)) != NULL) {

		Centipede* currObj = dynamic_cast<Centipede*>(gm->removeAndGet(i));
		this->centipedes.push(currObj);
		--this->currActive;

	}

}