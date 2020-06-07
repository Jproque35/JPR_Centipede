#include "Mushroom.h"
#include "MushroomNormalState.h"

Mushroom::Mushroom(float initX, float initY) {

	this->type = ObjectType::Mushroom;
	this->shape.setFillColor(Color::Magenta);
	
	GameObjectState* newState = new MushroomNormalState(this);
	this->currState = newState;
	this->states[newState->getType()] = newState;


}

Mushroom::~Mushroom() {

	//cout << "Destructing Mushroom..." << endl;

}

void Mushroom::init(float xPos, float yPos) {

	GameObject::init(xPos, yPos);

	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;


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