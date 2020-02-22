#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H
#pragma once
#include "ObjectMoveLeftCommand.h"
#include "ObjectMoveUpCommand.h"
#include "ObjectMoveDownCommand.h"
#include "ObjectMoveRightCommand.h"
#include "GridManager.h"

class ObjectController
{

protected:
	queue<ObjectCommand*> commands;
	void executeCommand(float elapsedTime);
	virtual void updateSub(float elapsedTime) = 0;
	virtual void collisionSub(GameObject* obj) = 0;

public:
	~ObjectController();
	void checkCollisionWithObjects(vector<vector<GameObject*>> objs);
	virtual GameObject* getData() = 0;
	void update(float elapsedTime);

};

#endif

