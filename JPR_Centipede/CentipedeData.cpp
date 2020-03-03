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

}

CentipedeData::~CentipedeData() {



}

CentipedeData& CentipedeData::operator=(const CentipedeData& obj) {

	return *this;

}

