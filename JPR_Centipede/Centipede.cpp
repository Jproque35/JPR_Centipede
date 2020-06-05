#include "Centipede.h"
#include "CentipedeHeadState.h"
#include "CentipedeBodyState.h"
#include "CommandFactory.h"
#include "ObjectCommand.h"
#include <iostream>

using namespace std;

Centipede::Centipede() : lastPos(Vector2f(-1.0f, -1.0f)) {

	this->type = ObjectType::CentipedeHead;
	this->shape.setFillColor(Color::Red);

	this->states[StateType::CentipedeHeadState] = new CentipedeHeadState(this);
	this->states[StateType::CentipedeBodyState] = new CentipedeBodyState(this);

	this->currState = this->states[StateType::CentipedeHeadState];

}

Centipede::~Centipede() {

	//cout << "Destroing Centipede objects..." << endl;

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

void Centipede::sendCommandToNext(ObjectCommand* cmd) {

	Centipede* currNext = this->next;

	currNext->setX(this->lastPos.x);
	currNext->setY(this->lastPos.y);
	currNext->setSpritePosition(currNext->getX(), currNext->getY());
	currNext->addCommand(CommandFactory::makeCommand(cmd->getType(), currNext));

}

void Centipede::handleFinishedCommand() {
	
	if (this->next != NULL) {

		this->sendCommandToNext(this->commands.front());

	}

	GameObject::handleFinishedCommand();

	this->lastPos.x = this->pos.x;
	this->lastPos.y = this->pos.y;

}