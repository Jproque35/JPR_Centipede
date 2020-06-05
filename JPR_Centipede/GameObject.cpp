#include "GameObject.h"
#include "GameObjectState.h"
#include "FontManager.h"
#include "ObjectCommand.h"
#include <iostream>

using namespace std;

GameObject::GameObject() {

	this->shape.setRadius(0.5f);
	this->shape.setPosition(this->pos);
	this->shape.setPointCount(15);

	FontManager* fm = FontManager::getInstance();

	this->posText.setPosition(Vector2f(0.0f, 0.0f));
	this->posText.setFont(*fm->get(0));
	this->posText.setCharacterSize(36);
	this->posText.setFillColor(sf::Color::White);
	this->posText.setOutlineColor(sf::Color::Black);
	this->posText.setOutlineThickness(1.0f);

}

GameObject::~GameObject() {

	//cout << "Destructing GameObject..." << endl;

	for (auto it = this->states.begin(); it != this->states.end(); ++it) {

		delete(it->second);

	}

	this->currState = NULL;

}

void GameObject::assignmentAux(const GameObject& obj) {

	this->currState = obj.currState;
	this->states = obj.states;
	this->type = obj.type;
	this->pos = obj.pos;
	this->shape = obj.shape;
	this->spr = obj.spr;
	this->xSpeed = obj.xSpeed;
	this->ySpeed = obj.ySpeed;
	this->posText = obj.posText;

}

ObjectType GameObject::getType() const {

	return this->type;

}

void GameObject::setStateType(StateType type) {

	if (this->states.count(type) > 0) {

		this->currState = this->states[type];

	}

}

StateType GameObject::getStateType() const {

	if (this->currState != NULL) {

		return this->currState->getType();

	}

	return StateType::Unknown;

}

GameObjectState* GameObject::getState() const {

	return this->currState;

}

void GameObject::setX(float xPos) {

	this->pos.x = xPos;

}

void GameObject::setY(float yPos) {

	this->pos.y = yPos;

}

float GameObject::getX() const {

	return this->pos.x;

}

float GameObject::getY() const {

	return this->pos.y;

}

float GameObject::getXSpeed() const {

	return this->xSpeed;

}

float GameObject::getYSpeed() const {

	return this->ySpeed;

}

Vector2f GameObject::getPosition() const {

	return this->pos;

}

void GameObject::setShapePosition(float xPos, float yPos) {

	this->shape.setPosition(Vector2f(xPos, yPos));

}

CircleShape GameObject::getShape() const {

	return this->shape;

}

void GameObject::setSpritePosition(float xPos, float yPos) {

	this->spr.setPosition(Vector2f(xPos, yPos));

}

Sprite GameObject::getSprite() const {

	return this->spr;

}

void GameObject::update(float elapsedTime) {

	if (this->currState != NULL) {

		this->currState->update(elapsedTime);

	}

}

void GameObject::setId(int id) {

	this->id = id;

}

int GameObject::getId() const {

	return this->id;

}

void GameObject::handleFinishedCommand() {

	ObjectCommand* currComm = this->commands.front();

	this->commands.pop();
	delete(currComm);
	currComm = NULL;

}

void GameObject::executeCommand(float elapsedTime) {

	if (this->commands.size() > 0) {

		ObjectCommand* currComm = this->commands.front();
		currComm->execute(elapsedTime);

		if (currComm->isFinished()) {

			this->handleFinishedCommand();

		}

	}

}

void GameObject::addCommand(ObjectCommand* cmd) {

	this->commands.push(cmd);

}

size_t GameObject::getCommandsSize() const {

	return this->commands.size();

}

FloatRect GameObject::getCollisionBox() const {

	FloatRect desire;

	desire.top = this->pos.y;
	desire.left = this->pos.x;
	desire.width = this->shape.getGlobalBounds().width;
	desire.height = this->shape.getGlobalBounds().height;

	//return this->shape.getGlobalBounds();

	return desire;

}