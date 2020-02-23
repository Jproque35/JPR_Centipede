#include "MushroomController.h"

MushroomController::MushroomController(Mushroom* context) {

	this->context = context;

}

void MushroomController::updateSub(float elapsedTime) {



}

void MushroomController::collisionSub(GameObject* obj) {

	if (this->context != obj) {

		float diameter0 = this->context->getShape().getRadius() * 2;
		float diameter1 = obj->getShape().getRadius() * 2;

		if (this->context->getPosition().y + diameter0 >= obj->getPosition().y ||
			this->context->getPosition().y <= obj->getPosition().y + diameter1) {

			if (this->context->getPosition().x + diameter0 >= obj->getPosition().x ||
				this->context->getPosition().x <= obj->getPosition().x + diameter1) {

				if (obj->getType() == ObjectType::PlayerProjectile && obj->isActive()) {

					cout << "Mushroom hit" << endl;
					this->context->deactivate();
					this->context->position = Vector2f(-1.0f, -1.0f);

				}


			}

		}

	}

}

GameObject* MushroomController::getData() {

	return this->context;

}