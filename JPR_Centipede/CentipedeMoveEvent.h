#pragma once
#include "GameEvent.h"
#include "CentipedeController.h"

class CentipedeMoveEvent :
	public GameEventListener
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
	CentipedeMoveEvent(const CentipedeMoveEvent& obj);
	~CentipedeMoveEvent();
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj);

	void update(float elapsedTime);

};

