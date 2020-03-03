#include "PlayerBulletFireCommand.h"
#include <iostream>

using namespace std;

PlayerBulletFireCommand::PlayerBulletFireCommand(PlayerBulletData* context) {

	this->context = context;
	this->context->active = true;
	this->type = CommandType::ShootBullet;

}

PlayerBulletFireCommand::PlayerBulletFireCommand(const PlayerBulletFireCommand& obj) {

	this->context = obj.context;
	this->distTravelled = obj.distTravelled;
	this->finished = obj.finished;
	this->type = obj.type;

}

PlayerBulletFireCommand::~PlayerBulletFireCommand() {}

PlayerBulletFireCommand& PlayerBulletFireCommand::operator=(const PlayerBulletFireCommand& obj) {

	return *this;

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