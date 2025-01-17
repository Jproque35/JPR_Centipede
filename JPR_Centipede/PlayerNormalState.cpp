#include "PlayerNormalState.h"
#include "PlayerHitEvent.h"
#include "PlayerInputEvent.h"
#include "CommandFactory.h"
#include "Player.h"
#include "ObjectCommand.h"

PlayerNormalState::PlayerNormalState(Player* context) {

	this->context = context;
	this->type = StateType::PlayerState;
	this->events.push_back(new PlayerHitEvent(context));
	this->events.push_back(new PlayerInputEvent(context));

}

PlayerNormalState::~PlayerNormalState() {

	//cout << "Destroying PlayerState..." << endl;

}

void PlayerNormalState::update(float elapsedTime) {

	this->context->executeCommand(elapsedTime);

}