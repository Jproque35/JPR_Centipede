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

MushroomNormalState::~MushroomNormalState() {

	//cout << "Deleting MushroomNormalState..." << endl;

}

MushroomNormalState& MushroomNormalState::operator=(const MushroomNormalState& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}