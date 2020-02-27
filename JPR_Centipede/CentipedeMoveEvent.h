#pragma once
#include "GameEvent.h"
#include "CentipedeController.h"

class CentipedeMoveEvent :
	public GameEvent
{

private:
	CentipedeController* context;
	GameObjectManager* gm;
	bool inReverse = false;
	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	bool nextLevelBlocked();
	void moveLeftRoutine();
	void moveRightRoutine();

public:
	CentipedeMoveEvent(GameObjectManager* gm, int i);
	void update(float elapsedTime);

};

