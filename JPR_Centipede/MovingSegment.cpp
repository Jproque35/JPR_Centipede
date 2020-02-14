#include "MovingSegment.h"

void MovingSegment::enquePosition(Vector2f* pos) {

	this->instructions->push(pos);

}

void MovingSegment::update(float elapsedTime) {

	Vector2f* currPos = this->instructions->front();

	if (currPos != NULL) {
		this->position.x = currPos->x;
		this->position.y = currPos->y;
		delete(currPos);
	}
	instructions->pop();

}