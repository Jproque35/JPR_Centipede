#include "CentipedeManager.h"
#include "Centipede.h"
#include "GameObjectFactory.h"

CentipedeManager* CentipedeManager::instance = NULL;

CentipedeManager::CentipedeManager() {

	this->objFactory = GameObjectFactory::getInstance();

}

CentipedeManager::~CentipedeManager() {}

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

vector<Centipede*> CentipedeManager::generateCentipede(int length) {

	vector<Centipede*> desire;

	if (length > 0) {

		desire.push_back((Centipede*)objFactory->makeObject(ObjectType::CentipedeHead, -1, -1));

		for (int i = 0; i < length - 1; ++i) {

			desire.push_back((Centipede*)objFactory->makeObject(ObjectType::CentipedeBody, -1, -1));

		}

		for (int i = 0; i < length - 1; ++i) {

			desire[i]->setNext(desire[i + 1]);
			cout << "Next for " << desire[i] << " set to " << desire[i + 1] << endl;

		}

		for (int i = length - 1; i > 0; --i) {

			desire[i]->setPrev(desire[i - 1]);
			cout << "prev for " << desire[i] << " set to " << desire[i - 1] << endl;

		}

	}

	this->currActive += length;

	return desire;

}