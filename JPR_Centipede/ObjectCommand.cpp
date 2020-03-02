#include "ObjectCommand.h"

bool ObjectCommand::isFinished() {

	return this->finished;

}

CommandType ObjectCommand::getType() {

	return this->type;

}