#include "MushroomData.h"

MushroomData::MushroomData(float initX, float initY) :ObjectData(initX, initY) {

	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::MushroomData;
	this->img.loadFromFile("assets/sprites/mushroom.png");
	this->spr.setTexture(this->img);
	this->init(initX, initY);

}

MushroomData::MushroomData(const MushroomData& obj) : ObjectData(obj) {

	this->health = int(obj.health);

}

MushroomData::~MushroomData() {}

MushroomData& MushroomData::operator=(const MushroomData& obj) {

	if (this != &obj) {



	}

	return *this;

}

void MushroomData::init(float xPos, float yPos) {

	this->position.x = xPos;
	this->position.y = yPos;

}

int MushroomData::getHealth() const {

	return this->health;

}

void MushroomData::setHealth(int health) {

	this->health = health;

}

void MushroomData::decrementHealth() {

	--this->health;

}