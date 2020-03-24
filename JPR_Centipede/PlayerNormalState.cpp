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

	ObjectCommand* newComm = CommandFactory::makeCommand(CommandType::MoveUp, this->context);

	this->cmdTbl[newComm->getType()] = newComm;

	newComm = CommandFactory::makeCommand(CommandType::MoveDown, this->context);

	this->cmdTbl[newComm->getType()] = newComm;

	newComm = CommandFactory::makeCommand(CommandType::MoveLeft, this->context);

	this->cmdTbl[newComm->getType()] = newComm;

	newComm = CommandFactory::makeCommand(CommandType::MoveRight, this->context);

	this->cmdTbl[newComm->getType()] = newComm;

}

PlayerNormalState::~PlayerNormalState() {

	cout << "Destroying PlayerState..." << endl;

}