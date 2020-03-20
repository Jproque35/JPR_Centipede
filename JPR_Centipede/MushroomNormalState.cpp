#include "MushroomNormalState.h"
#include "StateTypes.h"
#include "MushroomHitEvent.h"
#include "Mushroom.h"

MushroomNormalState::MushroomNormalState(Mushroom* context) : GenericState() {

	this->context = context;
	this->type = StateType::MushroomNormalState;
	this->events.push_back(new MushroomHitEvent(context));

}

MushroomNormalState::MushroomNormalState(const MushroomNormalState& obj) {}

MushroomNormalState::~MushroomNormalState() {}

MushroomNormalState& MushroomNormalState::operator=(const MushroomNormalState& obj) {

	return *this;

}