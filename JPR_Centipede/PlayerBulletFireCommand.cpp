#include "PlayerBulletFireCommand.h"
#include <iostream>
#include "SoundManager.h"
#include "PlayerBullet.h"

using namespace std;

PlayerBulletFireCommand::PlayerBulletFireCommand(PlayerBullet* context) {

	this->context = context;
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

		if (this->distTravelled == 0) {

			this->fireSound.play();

		}

		float moveDist = this->context->getYSpeed() * elapsedTime;

		this->context->setY( this->context->getY() - moveDist );

		this->distTravelled += moveDist;

		this->context->getShape().setPosition(this->context->getX(), this->context->getY());
		this->context->getSprite().setPosition(this->context->getX(), this->context->getY());

		if(this->distTravelled >= 10.0f) {

			this->finished = true;

		}

}