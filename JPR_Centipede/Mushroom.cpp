#include "Mushroom.h"

Mushroom::Mushroom(int id, float initX, float initY) :GameObject(id, initX, initY) {

	this->shape.setRadius(0.5);
	this->shape.setFillColor(Color::Magenta);
	this->type = ObjectType::Mushroom;

}