#include "CommandFactory.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveRightCommand.h"
#include "PlayerBullet.h"

ObjectCommand* CommandFactory::makeCommand(CommandType type, GameObject* obj) {

	if (type == CommandType::MoveUp) {

		return new ObjectMoveUpCommand(obj);

	}
	else if (type == CommandType::MoveDown) {

		return new ObjectMoveDownCommand(obj);

	}
	else if (type == CommandType::MoveLeft) {

		return new ObjectMoveLeftCommand(obj);

	}
	else if (type == CommandType::MoveRight) {

		return new ObjectMoveRightCommand(obj);

	}

}