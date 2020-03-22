#include "Mushroom.h"
#include "MushroomNormalState.h"

Mushroom::Mushroom(float initX, float initY) {

	this->type = ObjectType::Mushroom;
	this->shape.setFillColor(Color::Magenta);
	
	GameObjectState* newState = new MushroomNormalState(this);
	this->currState = newState;
	this->states[newState->getType()] = newState;


}

Mushroom::Mushroom(const Mushroom& obj) {



}

Mushroom::~Mushroom() {

	cout << "Destructing Mushroom..." << endl;

}

Mushroom& Mushroom::operator=(const Mushroom& obj) {

	GameObject::assignmentAux(obj);
	this->health = obj.health;

	return *this;

}

void Mushroom::init(float xPos, float yPos) {

	this->pos.x = xPos;
	this->pos.y = yPos;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
	this->shape.setPosition(this->pos);

}

void Mushroom::decrementHealth() {

	--this->health;

}

void Mushroom::resetHealth() {

	this->health = 4;

}

int Mushroom::getHealth() const {

	return this->health;

}