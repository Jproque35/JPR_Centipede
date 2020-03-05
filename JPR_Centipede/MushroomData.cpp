#include "MushroomData.h"

MushroomData::MushroomData(float initX, float initY) :ObjectData(initX, initY) {

	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::MushroomData;

}

MushroomData::MushroomData(const MushroomData& obj) : ObjectData(obj) {

	this->health = obj.health;
	this->inHitStun = obj.inHitStun;

}

MushroomData::~MushroomData() {}

MushroomData& MushroomData::operator=(const MushroomData& obj) {

	return *this;

}

int MushroomData::getHealth() {

	return this->health;

}

void MushroomData::setHealth(int health) {

	this->health = health;

}

void MushroomData::decrementHealth() {

	this->health--;

}