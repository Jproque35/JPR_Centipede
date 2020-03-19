#include "NullState.h"

NullState::NullState() {

	this->type = StateType::Unknown;

}

NullState::NullState(const NullState& obj) {

	this->type = obj.type;

}

NullState::~NullState() {}

NullState& NullState::operator=(const NullState& obj) {

	return *this;

}

void NullState::executeEventListeners(vector<GameEventListener*>& events, float elapsedTime) {


}

void NullState::executeCommand(queue<ObjectCommand*>& commands, float elapsedTime) {



}