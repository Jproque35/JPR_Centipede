#include "ObjectCommand.h"

ObjectCommand::~ObjectCommand() {

	//cout << "Destroying CommandObject..." << endl;

}

bool ObjectCommand::isFinished() {

	return this->finished;

}

CommandType ObjectCommand::getType() {

	return this->type;

}