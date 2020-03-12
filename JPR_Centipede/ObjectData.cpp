#include "ObjectData.h"
#include <sstream>

ObjectData::ObjectData(float initX, float initY) {

	this->position.x = initX;
	this->position.y = initY;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
	this->shape.setPosition(this->position);
	this->shape.setPointCount(15);

	this->font.loadFromFile("game_over.ttf");

	this->posText.setPosition(Vector2f(0.0f, 0.0f));
	this->posText.setFont(this->font);
	this->posText.setCharacterSize(36);
	this->posText.setFillColor(sf::Color::White);
	this->posText.setOutlineColor(sf::Color::Black);
	this->posText.setOutlineThickness(1.0f);

}

ObjectData::ObjectData(const ObjectData& obj) {

	this->position = obj.position;
	this->xSpeed = obj.xSpeed;
	this->ySpeed = obj.ySpeed;
	this->shape = CircleShape(this->shape);
	this->type = obj.type;
	this->active = obj.active;

}

ObjectData::~ObjectData() {}

ObjectData& ObjectData::operator=(const ObjectData& obj) {

	this->position = obj.position;
	this->xSpeed = obj.xSpeed;
	this->ySpeed = obj.ySpeed;
	this->shape = obj.shape;
	this->type = obj.type;
	this->active = obj.active;

	return *this;

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

CircleShape ObjectData::getShape() {

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

Text ObjectData::getPositionText() {

	stringstream ss;
	ss << "(" << this->position.x << "," << this->position.y << ")";
	this->posText.setString(ss.str());
	this->posText.setPosition(this->position);

	return this->posText;

}