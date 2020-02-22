#ifndef CENTIPEDECONTROLLER_H
#define CENTIPEDECONTROLLER_H
#pragma once
#include "ObjectController.h"
#include "Centipede.h"

enum class CentipedeDirection {Left, Right, Up, Down};

class CentipedeController : public ObjectController
{

private:
	Centipede* context;
	CentipedeDirection dir = CentipedeDirection::Left;
	bool inReverse = false;
	bool changingLevels = false;
	void queueLevelChangeCommand();
	void changeLevelRight();
	void changeLevelLeft();
	void updateSub(float elapsedTime);
	void collisionSub(GameObject* obj);

public:
	CentipedeController(Centipede* context);
	GameObject* getData();
	void checkCollision(float initX, float initY, float elapsedTime);

};

#endif

