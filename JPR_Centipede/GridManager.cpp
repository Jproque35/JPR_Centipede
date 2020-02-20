#include "GridManager.h"

GridManager::GridManager(int width, int height) {

	this->width = width;
	this->height = height;
	//this->objs.resize(this->width * this->height);
	this->objs = new string[width * height];

	for (int i = 0; i < this->objs->size(); i++) {

		this->objs[i] = "";
		cout << "Position " << i << " set to empty string" << endl;

	}

}

/*
GridManager::~GridManager() {

	if (this->objs != NULL) {

		delete(this->objs);
		this->objs = NULL;

	}

}*/

int GridManager::getKey(int x, int y) {

	return y * this->width + x;

}

int GridManager::getWidth() {

	return this->width;

}

int GridManager::getHeight() {

	return this->height;

}

void GridManager::swap(int x0, int y0, int x1, int y1) {

	int key0 = this->getKey(x0, y0);
	int key1 = this->getKey(x1, y1);

	string temp = this->objs[key1];
	this->objs[key1] = this->objs[key0];
	this->objs[key0] = temp;

}

void GridManager::add(string s, int x, int y) {

	this->objs[this->getKey(x, y)] = s;

}

void GridManager::erase(int x, int y) {

	this->objs[this->getKey(x, y)] = "";

}

string GridManager::get(int x, int y) {

	return this->objs[this->getKey(x, y)];

}