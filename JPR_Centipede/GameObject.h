#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>
#include "ObjectCommand.h"

using namespace sf;
using namespace std;

enum class ObjectType { Generic, Player, PlayerProjectile, Centipede, Mushroom, Unknown };

class GameObject {

	friend class ObjectCommand;
	friend class ObjectMoveUpCommand;
	friend class ObjectMoveDownCommand;
	friend class ObjectMoveLeftCommand;
	friend class ObjectMoveRightCommand;

protected:
	ObjectType type = ObjectType::Generic;
	Vector2f position;
	CircleShape shape;
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	bool active = false;
	int id = -1;

public:
	GameObject(float initX, float initY);
	void activate();
	void deactivate();
	bool isActive();
	int getId();
	ObjectType getType();
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	FloatRect getCollisionBox();
	CircleShape getShape();
	void setXVelocity(float xSpeed);
	void setYVelocity(float ySpeed);
	float getXVelocity();
	float getYVelocity();

};

#endif
