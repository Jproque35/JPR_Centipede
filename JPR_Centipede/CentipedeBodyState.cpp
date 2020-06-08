#include "CentipedeBodyState.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "GameEvent.h"
#include "CommandFactory.h"
#include "CentipedeBodyHitEvent.h"


CentipedeBodyState::CentipedeBodyState(Centipede* data) :
	CentipedeState(data)
{

	this->events.push_back(new CentipedeBodyHitEvent(data));

}

CentipedeBodyState::~CentipedeBodyState() {

	//cout << "Destroying CentipedeBodyState..." << endl;

}

void CentipedeBodyState::update(float elapsedTime) {

	/*
	if (this->lastPos.x < 0 || this->lastPos.y < 0) {

		this->lastPos = this->context->getPosition();

	}

	this->executeCommand(elapsedTime);*/

	this->context->executeCommand(elapsedTime);

}