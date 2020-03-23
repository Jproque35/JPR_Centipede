#include "EngineLib.h"
#include "CollisionMap.h"
#include "GameObject.h"

vector<GameObject*> EngineLib::getIntersectsObj(GameObject* obj) {

	CollisionMap* cm = CollisionMap::getInstance();
	FloatRect colBox = obj->getCollisionBox();

	int xStart = floor(colBox.left);
	int yStart = floor(colBox.top);
	int xEnd = floor(colBox.left + colBox.width);
	int yEnd = floor(colBox.top + colBox.height);

	vector<GameObject*> desire;
	vector<GameObject*> currList;

	for (int i = xStart; i <= xEnd; ++i) {

		for (int j = yStart; j <= yEnd; ++j) {

			currList = cm->get(i, j);

			for (int k = 0; k < currList.size(); ++k) {

				if (currList[k]->getCollisionBox().intersects(colBox)) {

					desire.push_back(currList[k]);

				}

			}

		}

	}

	return desire;

}

vector<GameObject*> EngineLib::getIntersectsPt(float xPos, float yPos) {

	CollisionMap* cm = CollisionMap::getInstance();

	vector<GameObject*> desire;
	vector<GameObject*> currList = cm->get(xPos, yPos);

	for (int i = 0; i < currList.size(); ++i) {

		if (currList[i]->getCollisionBox().contains(xPos, yPos)) {

			desire.push_back(currList[i]);

		}

	}

	return desire;

}