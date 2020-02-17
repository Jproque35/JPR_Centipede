#include "GameObject.h"

GameObject::~GameObject() {

	if (this->data != NULL) {

		delete(this->data);

	}

	if (this->state != NULL) {

		delete(this->state);

	}

}

ObjectData* GameObject::getData() {

	return this->data;

}

void GameObject::setState(ObjectState* state) {

	this->state = state;

}

void GameObject::update(float elapsedTime) {

	this->state->update(elapsedTime);

}