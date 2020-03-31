#include "Centipede.h"
#include "CentipedeHeadState.h"
#include "CentipedeBodyState.h"
#include <iostream>

using namespace std;

Centipede::Centipede() {

	this->type = ObjectType::CentipedeHead;
	this->shape.setFillColor(Color::Red);

	this->states[StateType::CentipedeHeadState] = new CentipedeHeadState(this);
	this->states[StateType::CentipedeBodyState] = new CentipedeBodyState(this);

	this->currState = this->states[StateType::CentipedeHeadState];

}

Centipede::Centipede(const Centipede& obj) {}

Centipede::~Centipede() {

	cout << "Destroing Centipede objects..." << endl;

}

Centipede& Centipede::operator=(const Centipede& obj) {

	if (this == &obj) {

		return *this;

	}

	return *this;

}

void Centipede::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 20.0f;
	this->ySpeed = 20.0f;
	this->shape.setPosition(this->pos);

	for (auto it = this->states.begin(); it != this->states.end(); ++it) {

		it->second->init();

	}

	cout << "Centipede initialized at position " << this->pos.x << ", " << this->pos.y << endl;
	//cout << "Sprite position for centipede is " << this->shape.getPosition().x << ", " << this->shape.getPosition().y << endl;

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