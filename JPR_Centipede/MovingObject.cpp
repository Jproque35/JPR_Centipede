#include "MovingObject.h"
#include <iostream>

MovingObject::MovingObject(float initX, float initY) :GameObject(initX, initY) {

	this->xSpeed = 100.0f;
	this->ySpeed = 100.0f;
	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->type = ObjectType::MovingObject;

}

void MovingObject::collideWithTopOrBottom() {

	this->ySpeed = -this->ySpeed;

}

void MovingObject::collideWithLeftOrRight() {

	this->xSpeed = -this->xSpeed;

}

void MovingObject::checkCollision(GameObject* objs[]) {



}

void MovingObject::checkCollision(GameObject* obj) {

	if (this->isPlayerProjectile(obj) && this->shape.getGlobalBounds().intersects(obj->getCollisionBox())) {

		this->shape.setFillColor(Color::Red);
		std::cout << "Object shot" << std::endl;

	} if (obj->getType() == ObjectType::DestroyableObject) {

		if (this->shape.getGlobalBounds().intersects(obj->getCollisionBox())) {

			this->ySpeed = -this->ySpeed;
			this->xSpeed = -this->xSpeed;

		}

	}
	else {

		this->shape.setFillColor(Color::White);

	}

}

bool MovingObject::isPlayerProjectile(GameObject* obj) {

	return obj->getType() == ObjectType::PlayerProjectile && obj->isActive();

}

void MovingObject::checkCollision(Window* w) {

	if (this->position.x < 0 || this->position.x + 50 > w->getSize().x) {

		this->collideWithLeftOrRight();

	}
	else if (this->position.y < 0 || this->position.y + 50> w->getSize().y) {

		this->collideWithTopOrBottom();

	}

}

void MovingObject::update(float elapsedTime) {

	this->position.x += this->xSpeed * elapsedTime;
	this->position.y += this->ySpeed * elapsedTime;
	this->shape.setPosition(this->position);

}