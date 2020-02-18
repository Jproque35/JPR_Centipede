#include "GameObject.h"

GameObject::GameObject(float initX, float initY) {

	this->position.x = initX;
	this->position.y = initY;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
	this->shape.setPosition(this->position);
	this->shape.setPointCount(15);

}

void GameObject::activate() {

	this->active = true;

}

void GameObject::deactivate() {

	this->active = false;

}

bool GameObject::isActive() {

	return this->active;

}

void GameObject::queueCommand(ObjectCommand* command) {

	this->commands.push(command);

}

int GameObject::getCommandQueueSize() {

	return this->commands.size();

}

ObjectType GameObject::getType() {

	return this->type;

}

void GameObject::setPosition(Vector2f pos) {

	this->position = pos;

}

Vector2f GameObject::getPosition() {

	return this->position;

}

FloatRect GameObject::getCollisionBox() {

	return this->shape.getGlobalBounds();

}

CircleShape GameObject::getShape() {

	return this->shape;

}

void GameObject::setXVelocity(float xSpeed) {

	this->xSpeed = xSpeed;

}

void GameObject::setYVelocity(float ySpeed) {

	this->ySpeed = ySpeed;

}

float GameObject::getXVelocity() {

	return this->xSpeed;

}

float GameObject::getYVelocity() {

	return this->ySpeed;

}