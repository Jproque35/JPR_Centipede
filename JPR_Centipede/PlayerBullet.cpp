#include "PlayerBullet.h"
#include "PlayerBulletState.h"

PlayerBullet::PlayerBullet(float initX, float initY) {

	this->shape.setRadius(0.2f);
	this->shape.setFillColor(Color::Yellow);
	this->type = ObjectType::PlayerBullet;

	PlayerBulletState* normalState = new PlayerBulletState(this);
	this->currState = normalState;
	this->states[normalState->getType()] = normalState;

}

PlayerBullet::~PlayerBullet() {

	//cout << "Destructing PlayerBullet object..." << endl;

}

void PlayerBullet::init(float xPos, float yPos) {

	GameObject::init(xPos, yPos);
	this->xSpeed = 0.0f;
	this->ySpeed = 40.0f;

}

