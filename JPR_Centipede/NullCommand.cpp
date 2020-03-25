#include "NullCommand.h"

NullCommand::NullCommand(GameObject* obj) {

	this->context = context;
	this->type = CommandType::Null;

}

NullCommand::NullCommand(const NullCommand& obj) {

	this->context = obj.context;
	this->type = obj.type;

}

NullCommand::~NullCommand() {}

NullCommand& NullCommand::operator=(const NullCommand& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

ObjectCommand* NullCommand::recontextCopy(GameObject* obj) {

	return new NullCommand(obj);

}

void NullCommand::execute(float elapsedTime) {



}