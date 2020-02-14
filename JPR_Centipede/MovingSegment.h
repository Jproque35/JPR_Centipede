#ifndef MOVINGSEGMENT_H
#define MOVINGSEGMENT_H
#pragma once
#include "GameObject.h"
#include <queue>
class MovingSegment :
	public GameObject
{

private:
	std::queue<Vector2f*>* instructions;
	MovingSegment* next;

public:
	MovingSegment(float initX, float initY);
	~MovingSegment();
	void enquePosition(Vector2f* pos);
	void checkCollision(GameObject* objs[]);
	void checkCollision(GameObject* obj);
	void checkCollision(Window* w);
	void update(float elapsedTime);

};

#endif
