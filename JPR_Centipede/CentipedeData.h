#ifndef CENTIPEDEDATA_H
#define CENTIPEDEDATA_H
#pragma once
#include "ObjectData.h"
#include "PlayerBullet.h"
#include <iostream>

enum class CentipedeDirection { Left, Right };

class Centipede;

class CentipedeData: public ObjectData {

private:
	CentipedeDirection dir = CentipedeDirection::Left;
	bool reversed = false;
	Centipede* next;
	Centipede* prev;

public:
	CentipedeData(float initX, float initY);
	CentipedeData(const CentipedeData& obj);
	~CentipedeData();
	CentipedeData& operator=(const CentipedeData& obj);
	void setDirection(CentipedeDirection dir);
	CentipedeDirection getDirection();
	void setDirectionLeft();
	void setDirectionRight();
	void setReversed();
	void unsetReversed();
	bool isReversed();
	void setNext(Centipede* next);
	Centipede* getNext();
	void setPrev(Centipede* prev);
	Centipede* getPrev();

};

#endif

