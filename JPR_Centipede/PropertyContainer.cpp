#include "PropertyContainer.h"

PropertyContainer::PropertyContainer(float initX, float initY) {

	this->position.x = initX;
	this->position.y = initY;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
	this->shape.setPosition(this->position);

}

void PropertyContainer::activate() {

	this->active = true;

}

void PropertyContainer::deactivate() {

	this->active = false;

}

bool PropertyContainer::isActive() {

	return this->active;

}

ObjectType PropertyContainer::getType() {

	return this->type;

}

Vector2f PropertyContainer::getPosition() {

	return this->position;

}

FloatRect PropertyContainer::getCollisionBox() {

	return this->shape.getGlobalBounds();

}

RectangleShape PropertyContainer::getShape() {

	return this->shape;

}

void PropertyContainer::setXVelocity(float xSpeed) {

	this->xSpeed = xSpeed;

}

void PropertyContainer::setYVelocity(float ySpeed) {

	this->ySpeed = ySpeed;

}

float PropertyContainer::getXVelocity() {

	return this->xSpeed;

}

float PropertyContainer::getYVelocity() {

	return this->ySpeed;

}