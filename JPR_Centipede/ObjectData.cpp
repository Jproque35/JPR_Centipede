#include "ObjectData.h"

ObjectData::ObjectData(float initX, float initY) {

	this->position.x = initX;
	this->position.y = initY;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
	this->shape.setPosition(this->position);

}

void ObjectData::activate() {

	this->active = true;

}

void ObjectData::deactivate() {

	this->active = false;

}

bool ObjectData::isActive() {

	return this->active;

}

ObjectType ObjectData::getType() {

	return this->type;

}

void ObjectData::setPosition(Vector2f pos) {

	this->position = pos;

}

Vector2f ObjectData::getPosition() {

	return this->position;

}

FloatRect ObjectData::getCollisionBox() {

	return this->shape.getGlobalBounds();

}

RectangleShape ObjectData::getShape() {

	return this->shape;

}

void ObjectData::setXVelocity(float xSpeed) {

	this->xSpeed = xSpeed;

}

void ObjectData::setYVelocity(float ySpeed) {

	this->ySpeed = ySpeed;

}

float ObjectData::getXVelocity() {

	return this->xSpeed;

}

float ObjectData::getYVelocity() {

	return this->ySpeed;

}