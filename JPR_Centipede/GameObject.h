#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>

using namespace sf;
using namespace std;

enum class ObjectType { Generic, Player, PlayerProjectile, Centipede, Mushroom, Unknown };

class GameObject {

	friend class ObjectCommand;
	friend class ObjectMoveUpCommand;
	friend class ObjectMoveDownCommand;
	friend class ObjectMoveLeftCommand;
	friend class ObjectMoveRightCommand;
	friend class ObjectActivateCommand;
	friend class ObjectDeactivateCommand;
	friend class ObjectSetPositionCommand;

protected:
	ObjectType type = ObjectType::Generic;
	Vector2f position;
	CircleShape shape;
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	bool active = false;

public:
	GameObject(float initX, float initY);
	GameObject(const GameObject& obj);
	~GameObject();
	GameObject& operator=(const GameObject& obj);

	void activate();
	void deactivate();
	bool isActive();
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
