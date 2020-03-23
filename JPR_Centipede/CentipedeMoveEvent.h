#ifndef CENTIPEDEMOVEEVENT_H
#define CENTIPEDEMOVEEVENT_H
#pragma once
#include "GameEvent.h"
#include "CentipedeDirection.h"

class CollisionMap;
class GameObjectManager;
class Centipede;

class CentipedeMoveEvent :
	public GameEventListener
{

private:
	GameObjectManager* gm;
	CollisionMap* cm;
	Centipede* context;

	bool intersectsMushroom(float xPos, float yPos);

	void queueLevelChangeCommand();
	void changeLevelAndDirection(CentipedeDirection dir);
	void moveLeftRoutine(float moveDist);
	void moveRightRoutine(float moveDist);

public:
	CentipedeMoveEvent(Centipede* context);
	CentipedeMoveEvent(const CentipedeMoveEvent& obj);
	~CentipedeMoveEvent();
	CentipedeMoveEvent& operator=(const CentipedeMoveEvent& obj);

	GameEventListener* recontextCopy(GameObject* obj);
	void update(float elapsedTime);

};

#endif
