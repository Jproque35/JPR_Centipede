#include "PlayerData.h"

PlayerData::PlayerData(float initX, float initY) : ObjectData(initX, initY) {

	this->xSpeed = 400.0f;
	this->ySpeed = 400.0f;
	this->shape.setSize(Vector2f(50.0f, 50.0f));
	this->shape.setFillColor(Color::Green);
	this->type = ObjectType::Player;

}
