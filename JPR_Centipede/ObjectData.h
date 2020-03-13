#ifndef OBJECTDATA_H
#define OBJECTDATA_H
#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>

using namespace sf;
using namespace std;

enum class ObjectType { Generic, PlayerData, PlayerProjectile, CentipedeData, MushroomData, Unknown };

class ObjectData {

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
	Texture img;
	Sprite spr;
	bool active = false;
	float xSpeed = 0.0f, ySpeed = 0.0f;
	Text posText;
	Font font;

public:
	ObjectData(float initX, float initY);
	ObjectData(const ObjectData& obj);
	~ObjectData();
	ObjectData& operator=(const ObjectData& obj);

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
	Text getPositionText();
	Sprite getSprite();

};

#endif
