#include "MovingObject.h"

void MovingObject::checkCollision(GameObject* objs[]) {

	this->state->checkCollision(objs);

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
	else {

		this->state->checkCollision(obj);

	}

}

bool MovingObject::isPlayerProjectile(GameObject* obj) {

	return obj->getType() == ObjectType::PlayerProjectile && obj->isActive();

}

void MovingObject::checkCollision(Window* w) {

	this->state->checkCollision(w);

}