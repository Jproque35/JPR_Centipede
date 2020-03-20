#include "Centipede.h"
#include "CentipedeHeadState.h"
#include "CentipedeBodyState.h"

Centipede::Centipede() {

	this->type = ObjectType::CentipedeHead;
	this->shape.setFillColor(Color::Red);

	this->states[StateType::CentipedeHeadState] = new CentipedeHeadState(this);
	this->states[StateType::CentipedeBodyState] = new CentipedeBodyState(this);

	this->currState = this->states[StateType::CentipedeHeadState];

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

void Centipede::setNext(Centipede* next) {

	this->next = next;

}

Centipede* Centipede::getNext() const {

	return this->next;

}

void Centipede::setPrev(Centipede* prev) {

	this->prev = prev;

}

Centipede* Centipede::getPrev() const {

	return this->prev;

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