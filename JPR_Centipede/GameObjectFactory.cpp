#include "GameObjectFactory.h"
#include "Mushroom.h"
#include "PlayerBullet.h"
#include "Player.h"
#include "Centipede.h"
#include <iostream>

GameObjectFactory* GameObjectFactory::instance = NULL;

GameObjectFactory::GameObjectFactory() {                                                                   

	this->player.push(new Player());

	for (int i = 0; i < 20; ++i) {

		this->centipedes.push(new Centipede());

	}

	for (int i = 0; i < 800; ++i) {

		//cout << "Creating reserve mmushroom " << i << endl;
		this->mushrooms.push(new Mushroom(-1, - 1));

	}

	for (int i = 0; i < 3; ++i) {

		this->bullets.push(new PlayerBullet(-1, -1));

	}

}

GameObjectFactory::~GameObjectFactory() {

	GameObject* currObj = NULL;

	while (this->player.size() > 0) {

		if (this->player.front() != NULL) {

			currObj = this->player.front();
			delete(currObj);
			currObj = NULL;

		}


		this->player.pop();
		
	}

	while (this->centipedes.size() > 0) {

		if (this->centipedes.front() != NULL) {

			currObj = this->centipedes.front();
			delete(currObj);
			currObj = NULL;

		}

		this->centipedes.pop();

	}

	while(this->mushrooms.size() > 0) {

		if (this->mushrooms.front() != NULL) {

			currObj = this->mushrooms.front();
			delete(currObj);
			currObj = NULL;

		}

		this->mushrooms.pop();
	}

	while (this->bullets.size() > 0) {

		if (this->bullets.front() != NULL) {

			currObj = this->bullets.front();
			delete(currObj);
			currObj = NULL;

		}

		this->bullets.pop();

	}

	while (this->misc.size() > 0) {

		if (this->misc.front() != NULL) {

			currObj = this->misc.front();
			delete(currObj);
			currObj = NULL;

		}

		this->misc.pop();

	}

}

GameObjectFactory* GameObjectFactory::getInstance() {

	if (!instance) {

		instance = new GameObjectFactory();

	}

	return instance;

}

void GameObjectFactory::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

	}

}

GameObject* GameObjectFactory::makeObject(ObjectType type, float initX, float initY) {

	
	if (type == ObjectType::Player && this->player.size() > 0) {
		
		//cout << "Creating Player object..." << endl;
		Player* player = this->player.front();
		this->player.pop();
		//cout << "Player object created." << endl;

		return player;

	}
	else if (type == ObjectType::PlayerBullet && this->bullets.size() > 0) {

		//cout << "Creating Bullet object..." << endl;
		PlayerBullet* playerBullet = bullets.front();
		bullets.pop();
		//playerBullet->init(initX, initY);
		//cout << "Bullet object created." << endl;

		return playerBullet;

	}
	else if (type == ObjectType::CentipedeHead && this->centipedes.size() > 0) {

		//cout << "Creating Centipede Head object..." << endl;
		Centipede* centipede = this->centipedes.front();
		this->centipedes.pop();
		centipede->setStateType(StateType::CentipedeHeadState);
		//cout << "Centipede object created." << endl;

		return centipede;

	}
	else if (type == ObjectType::CentipedeBody && this->centipedes.size() > 0) {

		//cout << "Creating Centipede Body object..." << endl;
		Centipede* centipede = this->centipedes.front();
		this->centipedes.pop();
		centipede->setStateType(StateType::CentipedeBodyState);
		//cout << "Centipede object created." << endl;

		return centipede;

	}
	else if (type == ObjectType::Mushroom && this->mushrooms.size() > 0) {

		//cout << "Creating Mushroom object..." << endl;
		Mushroom* mushroom = this->mushrooms.front();
		this->mushrooms.pop();
		//cout << "Mushroom object created." << endl;

		return mushroom;

	}

	return NULL;

}

void GameObjectFactory::storeObject(GameObject* obj) {

	if (obj->getType() == ObjectType::Player) {

		cout << "Stored Player object " << obj << " in reserve." << endl;
		this->player.push((Player*)obj);

	}
	if (obj->getType() == ObjectType::PlayerBullet) {

		cout << "Stored Bullet object " << obj << " in reserve." << endl;
		this->bullets.push((PlayerBullet*)obj);

	}
	else if (obj->getType() == ObjectType::Mushroom) {

		cout << "Stored Mushroom object " << obj << " in reserve." << endl;
		this->mushrooms.push((Mushroom*)obj);

	}
	else if (obj->getType() == ObjectType::CentipedeHead
		|| obj->getType() == ObjectType::CentipedeBody) {

		cout << "Stored Centipede object " << obj << " in reserve." << endl;
		this->centipedes.push((Centipede*)obj);

	} else {

		cout << "Stored object with unidentified type " << obj << " in reserve." << endl;
		this->misc.push(obj);

	}

}