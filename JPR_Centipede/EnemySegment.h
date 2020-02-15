#ifndef ENEMYSEGMENT_H
#define ENEMYSEGMENT_H
#pragma once
#include "GameObject.h"
#include <queue>

using namespace std;

class EnemySegment : public GameObject
{

private:
	queue<Vector2f>* posQueue = NULL;
	EnemySegment* next = NULL;
	float totalDist = 0.0f;

public:
	EnemySegment(float initX, float initY);
	~EnemySegment();
	void queuePosition(Vector2f pos);
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

#endif

