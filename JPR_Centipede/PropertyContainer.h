#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

enum class ObjectType { Generic, Player, PlayerProjectile, MovingObject, DestroyableObject };

class PropertyContainer {

protected:
	ObjectType type = ObjectType::Generic;
	Vector2f position;
	RectangleShape shape;
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	bool active = false;

public:
	PropertyContainer(float initX, float initY);
	void activate();
	void deactivate();
	bool isActive();
	ObjectType getType();
	Vector2f getPosition();
	FloatRect getCollisionBox();
	RectangleShape getShape();
	void setXVelocity(float xSpeed);
	void setYVelocity(float ySpeed);
	float getXVelocity();
	float getYVelocity();

};

#endif
