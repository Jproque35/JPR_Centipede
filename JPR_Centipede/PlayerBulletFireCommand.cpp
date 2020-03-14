#include "PlayerBulletFireCommand.h"
#include <iostream>
#include "SoundManager.h"

using namespace std;

PlayerBulletFireCommand::PlayerBulletFireCommand(PlayerBulletData* context) {

	this->context = context;
	this->context->active = true;
	this->type = CommandType::ShootBullet;


	SoundManager* sm = SoundManager::getInstance();
	this->sBuf = sm->get(0);
	this->fireSound.setBuffer(this->sBuf);

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

		if (this->distTravelled == 0) {

			this->fireSound.play();

		}

		this->context->position.y -= this->context->ySpeed * elapsedTime;
		this->distTravelled += this->context->ySpeed * elapsedTime;

		this->context->shape.setPosition(this->context->position);
		this->context->spr.setPosition(this->context->position);

		//if (this->context->position.y < 0.0f) {
		if(this->distTravelled >= 10.0f) {

			this->context->active = false;
			this->finished = true;

		}

	}

}