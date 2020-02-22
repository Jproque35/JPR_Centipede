#include "Centipede.h"


Centipede::Centipede(int id, float initX, float initY) :GameObject(id, initX, initY) {

	this->xSpeed = 20.0f;
	this->ySpeed = 20.0f;
	this->shape.setRadius(0.5);
	this->type = ObjectType::Centipede;

}

