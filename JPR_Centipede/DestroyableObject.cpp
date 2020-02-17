#include "DestroyableObject.h"

DestroyableObject::DestroyableObject(float initX, float initY) :ObjectData(initX, initY) {

	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::DestroyableObject;

}

void DestroyableObject::checkCollision(ObjectData* objs[]) {



}

void DestroyableObject::checkCollision(ObjectData* obj) {

	if (obj->getType() == ObjectType::PlayerProjectile && this->inHitStun == false) {

		this->inHitStun = true;
		this->health -= 1.0f;

	}

}

void DestroyableObject::checkCollision(Window* w) {



}

void DestroyableObject::update(float elapsedTime) {


}