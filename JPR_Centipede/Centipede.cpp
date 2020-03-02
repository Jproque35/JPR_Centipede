#include "Centipede.h"


Centipede::Centipede(float initX, float initY) :GameObject(initX, initY) {

	this->xSpeed = 15.0f;
	this->ySpeed = 15.0f;
	this->shape.setRadius(0.5f);
	this->shape.setFillColor(Color::Red);
	this->type = ObjectType::Centipede;

}

Centipede::Centipede(const Centipede& obj) :GameObject(obj) {

	this->dir = obj.dir;

}

Centipede::~Centipede() {



}

Centipede& Centipede::operator=(const Centipede& obj) {

	return *this;

}

