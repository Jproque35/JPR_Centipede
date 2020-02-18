#include "Mushroom.h"

Mushroom::Mushroom(float initX, float initY) :GameObject(initX, initY) {

	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::Mushroom;

}

void Mushroom::checkCollision(GameObject* obj) {

	if (obj->getType() == ObjectType::PlayerProjectile && this->inHitStun == false) {

		this->inHitStun = true;
		this->health -= 1.0f;

	}

}

void Mushroom::checkCollision(float xBoundary, float yBoundary) {



}

void Mushroom::update(float elapsedTime) {


}