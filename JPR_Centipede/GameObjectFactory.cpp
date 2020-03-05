#include "GameObjectFactory.h"

GameObject* GameObjectFactory::makeObject(ObjectType type, GameObjectManager gm, int initX, int initY) {

	if (type == ObjectType::PlayerData) {

		Player* player = new Player(initX, initY);

		return player;

	}

	return NULL;

}