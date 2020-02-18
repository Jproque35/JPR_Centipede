#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>
#include "ObjectCommand.h"

using namespace sf;
using namespace std;

enum class ObjectType { Generic, Player, PlayerProjectile, Centipede, Mushroom };

class GameObject {

protected:
	ObjectType type = ObjectType::Generic;
	queue<ObjectCommand*> commands;
	Vector2f position;
	CircleShape shape;
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	bool active = false;

public:
	GameObject(float initX, float initY);
	void activate();
	void deactivate();
	bool isActive();
	void queueCommand(ObjectCommand* command);
	int getCommandQueueSize();
	ObjectType getType();
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	FloatRect getCollisionBox();
	CircleShape getShape();
	void setXVelocity(float xSpeed);
	void setYVelocity(float ySpeed);
	float getXVelocity();
	float getYVelocity();
	virtual void checkCollision(GameObject* obj) = 0;
	virtual void checkCollision(float xBoundary, float yBoundary) = 0;
	virtual void update(float elapsedTime) = 0;

};

#endif
