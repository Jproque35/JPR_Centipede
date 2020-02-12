#include "DestroyableObject.h"

DestroyableObject::DestroyableObject(float initX, float initY) :GameObject(initX, initY) {

	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::DestroyableObject;

}

void DestroyableObject::checkCollision(GameObject* objs[]) {



}

void DestroyableObject::checkCollision(GameObject* obj) {

	if (obj->getType() == ObjectType::PlayerProjectile && this->inHitStun == false) {

		this->inHitStun = true;
		this->health -= 1.0f;

	}

}

void DestroyableObject::checkCollision(Window* w) {



}

void DestroyableObject::update(float elapsedTime) {


}