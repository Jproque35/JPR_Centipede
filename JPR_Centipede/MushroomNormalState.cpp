#include "MushroomNormalState.h"
#include "StateTypes.h"
#include "MushroomHitEvent.h"
#include "Mushroom.h"

MushroomNormalState::MushroomNormalState(Mushroom* context) : GenericState() {

	this->context = context;
	this->type = StateType::MushroomNormalState;
	this->events.push_back(new MushroomHitEvent(context));

}

MushroomNormalState::~MushroomNormalState() {

	//cout << "Deleting MushroomNormalState..." << endl;

}

void MushroomNormalState::update(float elapsedTime) {

	this->context->executeCommand(elapsedTime);

}