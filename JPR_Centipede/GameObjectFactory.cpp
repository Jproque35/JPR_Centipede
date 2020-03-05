#include "GameObjectFactory.h"

GameObject* GameObjectFactory::makeObject(ObjectType type, GameObjectManager* gm, float initX, float initY) {

	if (type == ObjectType::PlayerData) {

		cout << "Creating Player object..." << endl;
		Player* player = new Player(initX, initY);
		player->addEventListener(new PlayerInputEvent(gm, player));
		cout << "Player object created." << endl;

		return player;

	}
	else if (type == ObjectType::PlayerProjectile) {

		cout << "Creating Bullet object..." << endl;
		PlayerBullet* playerBullet = new PlayerBullet(initX, initY);
		playerBullet->addEventListener(new BulletFiredEvent(gm, playerBullet));
		playerBullet->addEventListener(new BulletCollideEvent(gm, playerBullet));
		cout << "Bullet object created." << endl;

		return playerBullet;

	}
	else if (type == ObjectType::CentipedeData) {

		cout << "Creating Centipede object..." << endl;
		Centipede* centipede = new Centipede(initX, initY);
		centipede->addEventListener(new CentipedeMoveEvent(gm, centipede));
		centipede->addEventListener(new CentipedeHitEvent(gm, centipede));
		cout << "Centipede object created." << endl;

		return centipede;

	}
	else if (type == ObjectType::MushroomData) {

		cout << "Creating Mushroom object..." << endl;
		Mushroom* mushroom = new Mushroom(initX, initY);
		mushroom->addEventListener(new MushroomHitEvent(gm, mushroom));
		cout << "Mushroom object created." << endl;

		return mushroom;

	}

	return NULL;

}