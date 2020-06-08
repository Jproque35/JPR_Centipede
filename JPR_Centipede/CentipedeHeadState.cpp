#include "CentipedeHeadState.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "GameEvent.h"
#include "CentipedeMoveEvent.h"
#include "CommandFactory.h"
#include "CentipedeHitEvent.h"

CentipedeHeadState::CentipedeHeadState(Centipede* data) :
	CentipedeState(data)
{

	this->type = StateType::CentipedeHeadState;

	this->events.push_back( new CentipedeMoveEvent(data) );
	this->events.push_back(new CentipedeHitEvent(data));

}

CentipedeHeadState::~CentipedeHeadState() {

	//cout << "Desstroying CentipedeHeadState..." << endl;

}

void CentipedeHeadState::update(float elapsedTime) {

	/*
	if(this->lastPos.x < 0 || this->lastPos.y < 0) {

		this->lastPos = this->context->getPosition();

	}

	this->executeCommand(elapsedTime);
	*/

	this->context->executeCommand(elapsedTime);
}