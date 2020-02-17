#include "EnemySegment.h"
#include <iostream>

using namespace std;

EnemySegment::EnemySegment(float initX, float initY):ObjectData(initX, initY) {


	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->shape.setFillColor(Color::Yellow);
	posQueue = new queue<Vector2f>();
	this->active = false;

}

EnemySegment::~EnemySegment() {

	delete(this->posQueue);

	if (this->next != NULL) {

		delete(this->next);

	}

}

void EnemySegment::queuePosition(Vector2f pos) {

	this->posQueue->push(pos);

}
void EnemySegment::checkCollision(ObjectData* objs[]) {}

void EnemySegment::checkCollision(ObjectData* obj) {}

void EnemySegment::checkCollision(Window* w) {}

void EnemySegment::update(float elapsedTime) {

	if (this->posQueue->size() > 0) {

		Vector2f currPos = this->posQueue->front();

		this->totalDist += abs(this->position.x - currPos.x);
		this->totalDist += abs(this->position.y - currPos.y);

		this->position.x = currPos.x;
		this->position.y = currPos.y;

		if (this->next != NULL) {

			this->next->queuePosition(currPos);

		}

		this->posQueue->pop();

	}

	if (this->totalDist >= 50.0f) {

		this->totalDist = 0.0f;
		if (this->next != NULL && !this->next->isActive()) {

			this->next->activate();

		}

	}

	this->shape.setPosition(this->position);

}
