#ifndef MUSHROOM_H
#define MUSHROOM_H
#pragma once
#include "ObjectData.h"

using namespace sf;

class DestroyableObject :
	public ObjectData
{

private:
	float health = 3.0f;
	bool inHitStun = false;
	bool isPlayerProjectile(GameObject* obj);

public:
	DestroyableObject(float initX, float initY);
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

#endif

