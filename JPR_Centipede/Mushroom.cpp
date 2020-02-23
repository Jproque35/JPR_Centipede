#include "Mushroom.h"

Mushroom::Mushroom(float initX, float initY) :GameObject(initX, initY) {

	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::Mushroom;

}