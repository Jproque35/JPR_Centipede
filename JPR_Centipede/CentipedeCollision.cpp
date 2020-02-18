#include "Centipede.h"

void Centipede::checkCollision(GameObject* obj) {

	if (this->isPlayerProjectile(obj) && this->shape.getGlobalBounds().intersects(obj->getCollisionBox())) {

		this->shape.setFillColor(Color::Red);
		std::cout << "Object shot" << std::endl;
		this->position.x = 0.0f;
		this->position.y = 0.0f;
		this->deactivate();
		obj->deactivate();

	}
	if (obj->getType() == ObjectType::Mushroom) {

		if (this->getCollisionBox().intersects(obj->getCollisionBox())) {

			if (this->getCollisionBox().top <= obj->getCollisionBox().top + obj->getShape().getSize().y) {

				this->ySpeed = -this->ySpeed;

			}

			if (this->getCollisionBox().left <= obj->getCollisionBox().left) {

				this->xSpeed = -this->xSpeed;

			}

		}

	}
	else {

		this->shape.setFillColor(Color::White);

	}

}

bool Centipede::isPlayerProjectile(GameObject* obj) {

	return obj->getType() == ObjectType::PlayerProjectile && obj->isActive();

}

void Centipede::checkCollision(float xBoundary, float yBoundary) {

	if (this->position.x <= 0 || this->position.x + this->shape.getSize().x >= xBoundary) {

		this->xSpeed = -this->xSpeed;

	}

	if (this->position.y <= 0 || this->position.y + this->shape.getSize().y >= yBoundary) {

		this->ySpeed = -this->ySpeed;

	}

}