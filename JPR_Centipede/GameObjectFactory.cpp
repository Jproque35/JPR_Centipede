#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::instance = NULL;

GameObjectFactory::GameObjectFactory() {

	for (int i = 0; i < 800; i++) {

		this->mushrooms.push(new Mushroom(-1, - 1));

	}

	for (int i = 0; i < 3; i++) {

		this->bullets.push(new PlayerBullet(-1, -1));

	}

}

GameObjectFactory::~GameObjectFactory() {

	while(this->mushrooms.size() > 0) {

		if (this->mushrooms.front() != NULL) {

			Mushroom* currObj = this->mushrooms.front();
			this->mushrooms.pop();
			delete(currObj);

		}

	}

	while (this->bullets.size() > 0) {

		if (this->bullets.front() != NULL) {

			PlayerBullet* currObj = this->bullets.front();
			this->bullets.pop();
			delete(currObj);

		}

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

	if (type == ObjectType::PlayerData) {

		cout << "Creating Player object..." << endl;
		Player* player = new Player(initX, initY);
		player->addEventListener(new PlayerInputEvent(player));
		cout << "Player object created." << endl;

		return player;

	}
	else if (type == ObjectType::PlayerProjectile) {

		cout << "Creating Bullet object..." << endl;
		PlayerBullet* playerBullet = bullets.front();
		bullets.pop();
		playerBullet->init(initX, initY);
		playerBullet->addEventListener(new BulletFiredEvent(playerBullet));
		playerBullet->addEventListener(new BulletCollideEvent(playerBullet));
		cout << "Bullet object created." << endl;

		return playerBullet;

	}
	else if (type == ObjectType::CentipedeData) {

		cout << "Creating Centipede Head object..." << endl;
		Centipede* centipede = new Centipede(initX, initY);
		centipede->setState(new CentipedeHeadState((CentipedeData*)centipede->getData()));

		centipede->addEventListener(new CentipedeMoveEvent(centipede));
		//centipede->addEventListener(new CentipedeHitEvent(centipede));
		cout << "Centipede object created." << endl;

		return centipede;

	}
	else if (type == ObjectType::CentipedeBody) {

		cout << "Creating Centipede Body object..." << endl;
		Centipede* centipede = new Centipede(initX, initY);
		centipede->setState(new CentipedeBodyState((CentipedeData*)centipede->getData()));

		//centipede->addEventListener(new CentipedeMoveEvent(centipede));
		//centipede->addEventListener(new CentipedeHitEvent(centipede));
		cout << "Centipede object created." << endl;

		return centipede;

	}
	else if (type == ObjectType::MushroomData) {

		cout << "Creating Mushroom object..." << endl;
		Mushroom* mushroom = this->mushrooms.front();
		this->mushrooms.pop();
		mushroom->init(initX, initY);
		mushroom->addEventListener(new MushroomHitEvent(mushroom));
		cout << "Mushroom object created." << endl;

		return mushroom;

	}

	return NULL;

}

void GameObjectFactory::storeObject(GameObject* obj) {

	if (obj->getData()->getType() == ObjectType::PlayerProjectile) {

		cout << "Stored Bullet object " << obj << " in reserve." << endl;
		this->bullets.push((PlayerBullet*)obj);

	}
	else if (obj->getData()->getType() == ObjectType::MushroomData) {

		cout << "Stored Mushroom object " << obj << " in reserve." << endl;
		this->mushrooms.push((Mushroom*)obj);

	}
	else {

		this->misc.push(obj);

	}

}