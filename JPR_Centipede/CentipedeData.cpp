#include "CentipedeData.h"


CentipedeData::CentipedeData(float initX, float initY) :ObjectData(initX, initY) {

	this->xSpeed = 15.0f;
	this->ySpeed = 15.0f;
	this->shape.setRadius(0.5f);
	this->shape.setFillColor(Color::Red);
	this->type = ObjectType::CentipedeData;

}

CentipedeData::CentipedeData(const CentipedeData& obj) :ObjectData(obj) {

	this->dir = obj.dir;
	this->reversed = obj.reversed;

}

CentipedeData::~CentipedeData() {



}

CentipedeData& CentipedeData::operator=(const CentipedeData& obj) {

	return *this;

}

CentipedeDirection CentipedeData::getDirection() {

	return this->dir;

}

void CentipedeData::setDirection(CentipedeDirection dir) {

	this->dir = dir;

}

void CentipedeData::setDirectionLeft() {

	this->dir = CentipedeDirection::Left;

}
void CentipedeData::setDirectionRight() {

	this->dir = CentipedeDirection::Right;

}
void CentipedeData::setReversed() {

	this->reversed = true;

}

void CentipedeData::unsetReversed() {

	this->reversed = false;

}

bool CentipedeData::isReversed() {

	return this->reversed;

}

void CentipedeData::setNext(Centipede* next) {

	this->next = next;

}

Centipede* CentipedeData::getNext() {

	return this->next;

}

void CentipedeData::setPrev(Centipede* prev) {

	this->prev = prev;

}

Centipede* CentipedeData::getPrev() {

	return this->prev;

}

