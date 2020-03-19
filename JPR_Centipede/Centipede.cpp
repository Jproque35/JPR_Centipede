#include "Centipede.h"

Centipede::Centipede() {

	this->type = ObjectType::CentipedeHead;
	this->shape.setFillColor(Color::Red);

}

Centipede::Centipede(const Centipede& obj) {}

Centipede::~Centipede() {}

Centipede& Centipede::operator=(const Centipede& obj) {

	return *this;

}

void Centipede::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 8.0f;
	this->ySpeed = 8.0f;
	this->shape.setPosition(this->pos);

}

void Centipede::setDirection(CentipedeDirection dir) {

	this->dir = dir;

}

CentipedeDirection Centipede::getDirection() const {

	return this->dir;

}

void Centipede::setReversed() {

	this->reversed = true;

}

void Centipede::unsetReversed() {

	this->reversed = false;

}

bool Centipede::isReversed() const {

	return this->reversed;

}