#include "PlayerInputEvent.h"

PlayerInputEvent::PlayerInputEvent(GameObjectManager* gm, int i) {

	this->gm = gm;
	this->context = (PlayerController*)(gm->get(i));

}

void PlayerInputEvent::update(float elapsedTime) {

	Vector2f currPos = this->context->getData()->getPosition();
	float diameter = this->context->getData()->getShape().getRadius() * 2;

	if (Keyboard::isKeyPressed(Keyboard::W)) {

		if (currPos.y - 1.0f >= 0
			&& !this->gm->hasType(ObjectType::Mushroom, currPos.x, currPos.y - 1.0f)) {

			this->context->setKey(Keyboard::W);

		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {

		if (currPos.y + diameter + 1.0f < this->gm->getGridHeight()
			&& !this->gm->hasType(ObjectType::Mushroom, currPos.x, currPos.y + 1)) {

			this->context->setKey(Keyboard::S);

		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {

		if (currPos.x - 1.0f >= 0
			&& !this->gm->hasType(ObjectType::Mushroom, currPos.x - 1.0f, currPos.y)) {

			this->context->setKey(Keyboard::A);

		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {

		if (currPos.x + diameter + 1.0f < this->gm->getGridWidth()
			&& !this->gm->hasType(ObjectType::Mushroom, currPos.x + 1, currPos.y)) {
			this->context->setKey(Keyboard::D);
		
		}
	}

}