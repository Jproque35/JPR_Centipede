#include "MushroomLoader.h"

MushroomLoader::MushroomLoader() {

	for (int i = 0; i < 800; ++i) {

		this->objs.push(new Mushroom(-1, -1));

	}

}

MushroomLoader::MushroomLoader(const MushroomLoader& obj) {


}

MushroomLoader::~MushroomLoader() {}

MushroomLoader& MushroomLoader::operator=(const MushroomLoader& obj) {

	return *this;

}

GameObject* MushroomLoader::makeObject(ObjectType type) {

	if (type == ObjectType::MushroomData) {

		GameObject* currObj = this->objs.front();
		this->objs.pop();

		this->addEvents(currObj);

		return currObj;

	}
	else {

		return NULL;

	}

}

void MushroomLoader::addEvents(GameObject* obj) {

	Mushroom* currObj = (Mushroom*)obj;
	currObj->addEventListener(new MushroomHitEvent(currObj));

}

void MushroomLoader::storeObject(GameObject* obj) {

	if (obj->getData()->getType() == ObjectType::MushroomData) {

		this->objs.push((Mushroom*)obj);

	}
	else {

		cout << "Unknown object" << endl;

	}

}