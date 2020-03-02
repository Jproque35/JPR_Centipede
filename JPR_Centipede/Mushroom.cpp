#include "Mushroom.h"

Mushroom::Mushroom(float initX, float initY) :GameObject(initX, initY) {

	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::Mushroom;

}

Mushroom::Mushroom(const Mushroom& obj) : GameObject(obj) {

	this->health = obj.health;
	this->inHitStun = obj.inHitStun;

}

Mushroom::~Mushroom() {}

Mushroom& Mushroom::operator=(const Mushroom& obj) {

	return *this;

}