#include "ObjectData.h"
#include <sstream>

ObjectData::ObjectData(float initX, float initY) {

	this->position.x = initX;
	this->position.y = initY;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
	this->shape.setPosition(this->position);
	this->shape.setPointCount(15);

	//this->img.loadFromFile("assets/sprites/centi.png");
	//this->spr.setTexture(this->img);
	this->spr.setPosition(this->position);

	this->font.loadFromFile("game_over.ttf");

	this->posText.setPosition(Vector2f(0.0f, 0.0f));
	this->posText.setFont(this->font);
	this->posText.setCharacterSize(36);
	this->posText.setFillColor(sf::Color::White);
	this->posText.setOutlineColor(sf::Color::Black);
	this->posText.setOutlineThickness(1.0f);

}

ObjectData::ObjectData(const ObjectData& obj) {

	this->position = Vector2f(obj.position);
	this->xSpeed = obj.xSpeed;
	this->ySpeed = obj.ySpeed;
	this->shape = CircleShape(obj.shape);
	this->type = obj.type;
	this->active = obj.active;
	this->font = Font(obj.font);
	this->posText = Text(obj.posText);

}

ObjectData::~ObjectData() {}

ObjectData& ObjectData::operator=(const ObjectData& obj) {

	this->position = obj.position;
	this->xSpeed = obj.xSpeed;
	this->ySpeed = obj.ySpeed;
	this->shape = obj.shape;
	this->type = obj.type;
	this->active = obj.active;
	this->font = obj.font;
	this->posText = obj.posText;

	return *this;

}

void ObjectData::activate() {

	this->active = true;

}

void ObjectData::deactivate() {

	this->active = false;

}

bool ObjectData::isActive() const {

	return this->active;

}

ObjectType ObjectData::getType() {

	return this->type;

}

void ObjectData::setPosition(Vector2f pos) {

	this->position = pos;

	stringstream ss;
	ss << "(" << this->position.x << "," << this->position.y << ")";
	this->posText.setString(ss.str());
	this->posText.setPosition(this->position);

}

Vector2f ObjectData::getPosition() const {

	return this->position;

}

FloatRect ObjectData::getCollisionBox() const {

	return this->shape.getGlobalBounds();

}

CircleShape ObjectData::getShape() const {

	return this->shape;

}

void ObjectData::setXVelocity(float xSpeed) {

	this->xSpeed = xSpeed;

}

void ObjectData::setYVelocity(float ySpeed) {

	this->ySpeed = ySpeed;

}

float ObjectData::getXVelocity() const {

	return this->xSpeed;

}

float ObjectData::getYVelocity() const {

	return this->ySpeed;

}

Text ObjectData::getPositionText() const {

	return this->posText;

}

Sprite ObjectData::getSprite() const {

	return this->spr;

}