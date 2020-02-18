#ifndef CENTIPEDECONTROLLER_H
#define CENTIPEDECONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "Centipede.h"
#include "CentipedeMoveLeftCommand.h"
#include "CentipedeMoveRightCommand.h"
#include "CentipedeMoveDownCommand.h"

enum class CentipedeDirection {Left, Right, Up, Down};

class CentipedeController : public ObjectController
{

private:
	Centipede* context;
	CentipedeDirection dir = CentipedeDirection::Left;

public:
	CentipedeController(Centipede* context);
	void checkCollision(float initX, float initY);
	void update(float elapsedTime);

};

#endif

