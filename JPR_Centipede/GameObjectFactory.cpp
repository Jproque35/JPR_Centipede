#include "GameObjectFactory.h"

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
		PlayerBullet* playerBullet = new PlayerBullet(initX, initY);
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

		centipede->addEventListener(new CentipedeMoveEvent(centipede));
		centipede->addEventListener(new CentipedeHitEvent(centipede));
		cout << "Centipede object created." << endl;

		return centipede;

	}
	else if (type == ObjectType::MushroomData) {

		cout << "Creating Mushroom object..." << endl;
		Mushroom* mushroom = new Mushroom(initX, initY);
		mushroom->addEventListener(new MushroomHitEvent(mushroom));
		cout << "Mushroom object created." << endl;

		return mushroom;

	}

	return NULL;

}