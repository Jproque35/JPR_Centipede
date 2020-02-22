#include "PlayerBulletFireCommand.h"
#include <iostream>

using namespace std;

PlayerBulletFireCommand::PlayerBulletFireCommand(PlayerBullet* context, float x, float y) {

	//cout << "Bullet fire at pos " << x << " " << y << endl;

	this->context = context;
	this->context->active = true;
	this->context->position.x = x;
	this->context->position.y = y;

}


void PlayerBulletFireCommand::execute(float elapsedTime) {

	if (this->context->active) {

		this->context->position.y -= this->context->ySpeed * elapsedTime;
		this->distTravelled += this->context->ySpeed * elapsedTime;
		this->context->shape.setPosition(context->position);

		//if (this->context->position.y < 0.0f) {
		if(this->distTravelled >= 10.0f) {

			this->context->active = false;
			this->finished = true;

		}

	}

}