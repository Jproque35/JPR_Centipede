#include "CentipedeHeadState.h"
#include "Centipede.h"
#include "GameObjectManager.h"
#include "ObjectCommand.h"
#include "GameEvent.h"
#include "CentipedeMoveEvent.h"
#include "CommandFactory.h"
#include "CentipedeHitEvent.h"

CentipedeHeadState::CentipedeHeadState(Centipede* data) {

	this->context = data;
	this->lastPos = Vector2f(-1.0f, -1.0f);
	this->type = StateType::CentipedeHeadState;

	this->events.push_back( new CentipedeMoveEvent(data) );
	//this->events.push_back(new CentipedeHitEvent(data));

	cout << "lastPos initialized to " << this->lastPos.x << ", " << this->lastPos.y << endl;

}

CentipedeHeadState::~CentipedeHeadState() {

	//cout << "Desstroying CentipedeHeadState..." << endl;

}

CentipedeHeadState& CentipedeHeadState::operator=(const CentipedeHeadState& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

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