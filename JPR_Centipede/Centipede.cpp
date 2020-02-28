#include "Centipede.h"


Centipede::Centipede(float initX, float initY) :GameObject(initX, initY) {

	this->xSpeed = 15.0f;
	this->ySpeed = 15.0f;
	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Red);
	this->type = ObjectType::Centipede;

}

