#include "MovingObject.h"

void MovingObject::checkCollision(GameObject* objs[]) {



}

void MovingObject::checkCollision(GameObject* obj) {

	if (this->isPlayerProjectile(obj) && this->shape.getGlobalBounds().intersects(obj->getCollisionBox())) {

		this->shape.setFillColor(Color::Red);
		std::cout << "Object shot" << std::endl;
		this->position.x = 0.0f;
		this->position.y = 0.0f;
		this->deactivate();
		obj->deactivate();

	}
	if (obj->getType() == ObjectType::DestroyableObject) {

		this->collideWithObstacle(obj);

	}
	else {

		this->shape.setFillColor(Color::White);

	}

}

void MovingObject::collideWithObstacle(GameObject* obj) {

	if (this->shape.getGlobalBounds().intersects(obj->getCollisionBox())) {

		std::cout << "Collided with obstacle" << std::endl;

		if (this->shape.getGlobalBounds().left < obj->getCollisionBox().left + 50.0f && this->currState == MovingObjectState::MoveLeft) {

			this->lastSideState = MovingObjectState::MoveLeft;
			this->currState = MovingObjectState::MoveDown;

		}
		else if (this->shape.getGlobalBounds().left + 50.0f > obj->getCollisionBox().left && this->currState == MovingObjectState::MoveRight) {

			this->lastSideState = MovingObjectState::MoveRight;
			this->currState = MovingObjectState::MoveDown;

		}

	}

}

bool MovingObject::isPlayerProjectile(GameObject* obj) {

	return obj->getType() == ObjectType::PlayerProjectile && obj->isActive();

}

void MovingObject::checkCollision(Window* w) {

	if (this->collideBottomSide(w)) {


		this->currState = MovingObjectState::MoveDown;

	}

	if (this->collideLeftSide(w) || this->collideRightSide(w)) {

		this->lastSideState = this->currState;
		this->currState = MovingObjectState::MoveDown;

	}

}

bool MovingObject::collideTopSide(Window* w) {

	if (this->currState == MovingObjectState::MoveUp) {

		return this->shape.getGlobalBounds().top < 0;

	}

	return false;

}

bool MovingObject::collideBottomSide(Window* w) {

	if (this->currState == MovingObjectState::MoveDown) {

		return this->shape.getGlobalBounds().top + 50.0f > w->getSize().y;

	}

	return false;

}

bool MovingObject::collideLeftSide(Window* w) {

	if (this->currState == MovingObjectState::MoveLeft) {

		return this->shape.getGlobalBounds().left < 0;

	}

	return false;

}

bool MovingObject::collideRightSide(Window* w) {

	if (this->currState == MovingObjectState::MoveRight) {

		return this->shape.getGlobalBounds().left + 50.0f > w->getSize().x;

	}

	return false;

}