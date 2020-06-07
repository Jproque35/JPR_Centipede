#include "CentipedeBodyState.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "GameEvent.h"
#include "CommandFactory.h"
#include "CentipedeBodyHitEvent.h"


CentipedeBodyState::CentipedeBodyState(Centipede* data) {

	this->context = data;
	this->lastPos = Vector2f(-1.0f, -1.0f);
	this->events.push_back(new CentipedeBodyHitEvent(data));

	cout << "lastPos initialized to " << this->lastPos.x << ", " << this->lastPos.y << endl;

}

CentipedeBodyState::~CentipedeBodyState() {

	//cout << "Destroying CentipedeBodyState..." << endl;

}

CentipedeBodyState& CentipedeBodyState::operator=(const CentipedeBodyState& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

void CentipedeBodyState::update(float elapsedTime) {

	/*
	if (this->lastPos.x < 0 || this->lastPos.y < 0) {

		this->lastPos = this->context->getPosition();

	}

	this->executeCommand(elapsedTime);*/

	this->context->executeCommand(elapsedTime);

}