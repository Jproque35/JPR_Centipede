#include "CollisionMap.h"
#include "GameObject.h"
#include "GameObjectManager.h"

CollisionMap* CollisionMap::instance = NULL;

CollisionMap::CollisionMap() {}

CollisionMap::~CollisionMap() {}

CollisionMap* CollisionMap::getInstance() {

	if (!instance) {

		instance = new CollisionMap();

	}

	return instance;

}

void CollisionMap::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

	}

}

void CollisionMap::init(int width, int height) {

	this->width = width;
	this->height = height;
	this->map.resize(this->width * this->height);

}

inline bool CollisionMap::inBounds(float x, float y) {

	if (0 <= floor(x) && floor(x) < this->width) {

		return 0 <= floor(y) && floor(y) < this->height;
		
	}

	return false;

}

inline int CollisionMap::getKey(float x, float y) {

	return floor(y) * this->width + floor(x);

}

int CollisionMap::getWidth() {

	return this->width;

}

int CollisionMap::getHeight() {

	return this->height;

}

void CollisionMap::buildMap() {

	GameObjectManager* gm = GameObjectManager::getInstance();

	for (int i = 0; i < gm->size(); ++i) {

		this->add(gm->get(i));

	}

}

void CollisionMap::clear() {

	this->map.clear();
	this->map.resize(this->width * this->height);

}

void CollisionMap::add(GameObject* obj) {

	if (obj != NULL) {
		FloatRect colBox = obj->getCollisionBox();

		int xStart = floor(colBox.left);
		int yStart = floor(colBox.top);
		int xEnd = floor(xStart + colBox.width);
		int yEnd = floor(yStart + colBox.height);

		for (int i = xStart; i <= xEnd; ++i) {

			for (int j = yStart; j <= yEnd; ++j) {

				if (this->inBounds(i, j)) {

					this->map[this->getKey(i, j)].push_back(obj);

				}

			}

		}

	}

}

vector<GameObject*> CollisionMap::get(int x, int y) {

	if (this->inBounds(x, y)) {

		return this->map[this->getKey(x, y)];

	}

	return {};

}