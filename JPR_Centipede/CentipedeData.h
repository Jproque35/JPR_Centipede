#ifndef CENTIPEDEDATA_H
#define CENTIPEDEDATA_H
#pragma once
#include "ObjectData.h"
#include "PlayerBullet.h"
#include <iostream>

enum class CentipedeDirection { Left, Right };

class CentipedeData: public ObjectData {

	friend class Centipede;
	friend class CentipedeMoveEvent;

private:
	CentipedeDirection dir = CentipedeDirection::Left;

public:
	CentipedeData(float initX, float initY);
	CentipedeData(const CentipedeData& obj);
	~CentipedeData();
	CentipedeData& operator=(const CentipedeData& obj);

};

#endif

