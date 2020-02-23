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
	GridManager* grid;
	CentipedeController* next = NULL;
	bool inReverse = false;
	void updateSub(float elapsedTime);
	void collisionSub(GameObject* obj);
	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	bool nextLevelBlocked();
	void moveLeftRoutine();
	void moveRightRoutine();

protected:
	//void handleFinishedCommand(ObjectCommand* command);

public:
	CentipedeController(Centipede* context, GridManager* grid);
	GameObject* getData();
	void setNext(CentipedeController* next);

};

#endif

