#include "GridManager.h"

GridManager::GridManager(int width, int height) {

	this->width = width;
	this->height = height;
	this->objs.resize(this->width * this->height);

	for (int i = 0; i < width * height; i++) {

		cout << "Position " << i << " has size " << this->objs[i].size() << endl;

	}

}


GridManager::~GridManager() {

}

int GridManager::getKey(int x, int y) {

	return y * this->width + x;

}

int GridManager::getWidth() {

	return this->width;

}

int GridManager::getHeight() {

	return this->height;

}

void GridManager::clear() {

	this->objs.clear();
	this->objs.resize(this->width * this->height);

}

void GridManager::add(string s, int x, int y) {

	this->objs[this->getKey(x, y)].push_back(s);

}

vector<string> GridManager::get(int x, int y) {

	return this->objs[this->getKey(x, y)];

}