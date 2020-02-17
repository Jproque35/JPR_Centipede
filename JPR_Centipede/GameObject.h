#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class ObjectType { Generic, Player, PlayerProjectile, MovingObject, DestroyableObject };

class GameObject {

protected:
	ObjectType type = ObjectType::Generic;
	Vector2f position;
	RectangleShape shape;
	float xSpeed = 0.0f;
	float ySpeed = 0.0f;
	bool active = false;

public:
	GameObject(float initX, float initY);
	void activate();
	void deactivate();
	bool isActive();
	ObjectType getType();
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	FloatRect getCollisionBox();
	RectangleShape getShape();
	void setXVelocity(float xSpeed);
	void setYVelocity(float ySpeed);
	float getXVelocity();
	float getYVelocity();
	virtual void checkCollision(GameObject* objs[]) = 0;
	virtual void checkCollision(GameObject* obj) = 0;
	virtual void checkCollision(Window* w) = 0;
	virtual void update(float elapsedTime) = 0;

};
