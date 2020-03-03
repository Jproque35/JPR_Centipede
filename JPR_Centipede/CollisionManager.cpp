#include "CollisionManager.h"

bool CollisionManager::intersects(GameObject* obj1, GameObject* obj2) {

	ObjectData* data1 = obj1->getData();
	ObjectData* data2 = obj2->getData();

	if (data1 != data2) {

		float diameter0 = data1->getShape().getRadius() * 2;
		float diameter1 = data2->getShape().getRadius() * 2;

		if (data1->getPosition().y + diameter0 >= data2->getPosition().y ||
			data1->getPosition().y <= data2->getPosition().y + diameter1) {

			if (data1->getPosition().x + diameter0 >= data2->getPosition().x ||
				data1->getPosition().x <= data2->getPosition().x + diameter1) {

				return true;

			}

		}

	}

	return false;

}

vector<vector<GameObject*>> CollisionManager::getGridObjects(GameObject* obj, GameObjectManager* gm) {

	int xLo = floor(obj->getData()->getPosition().x);
	int yLo = floor(obj->getData()->getPosition().y);
	float diameter = 2 * obj->getData()->getShape().getRadius();
	int xHi = floor(obj->getData()->getPosition().x + diameter);
	int yHi = floor(obj->getData()->getPosition().y + diameter);

	vector<vector<GameObject*>> desire;

	for (int i = xLo; i < xHi; i++) {

		for (int j = yLo; j < yHi; j++) {

			desire.push_back(gm->get(i, j));

		}
	}

	return desire;

}