#ifndef CENTIPEDEDATA_H
#define CENTIPEDEDATA_H
#pragma once
#include "ObjectData.h"
#include "PlayerBullet.h"
#include <iostream>

enum class CentipedeDirection { Left, Right };

class CentipedeData: public ObjectData {

	friend class Centipede;

private:
	CentipedeDirection dir = CentipedeDirection::Left;
	bool reversed = false;

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

};

#endif

