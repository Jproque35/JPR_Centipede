#include "MovingObject.h"

void Enemy::checkCollision(ObjectData* obj) {

	if (this->isPlayerProjectile(obj) && this->getCollisionBox().intersects(obj->getCollisionBox())) {

		this->shape.setFillColor(Color::Red);
		std::cout << "Object shot" << std::endl;
		this->position.x = 0.0f;
		this->position.y = 0.0f;
		this->deactivate();
		obj->deactivate();

	}
	else {

		this->shape.setFillColor(Color::White);
		
		if (this->currState != NULL) {

			this->currState->checkCollision(obj);

		}

	}

}

bool Enemy::isPlayerProjectile(ObjectData* obj) {

	return obj->getType() == ObjectType::PlayerProjectile && obj->isActive();

}

void Enemy::checkCollision(Window* w) {

	if (this->currState != NULL) {
	
		this->currState->checkCollision(w);
	
	}

}