#ifndef OBJECTDATA_H
#define OBJECTDATA_H
#pragma once
#include "SoundManager.h"
#include "SpriteManager.h"
#include <queue>
#include <iostream>

using namespace sf;
using namespace std;

enum class ObjectType { Generic, PlayerData, PlayerProjectile, CentipedeData, CentipedeBody, MushroomData, Unknown };

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
	int id = -1;
	Text posText;
	Font font;

public:
	ObjectData(float initX, float initY);
	ObjectData(const ObjectData& obj);
	~ObjectData();
	ObjectData& operator=(const ObjectData& obj);

	virtual void init(float xPos, float yPos) = 0;
	void setId(int id);
	int getId();
	void activate();
	void deactivate();
	bool isActive() const;
	ObjectType getType();
	void setX(float xPos);
	void setY(float YPos);
	void setPosition(Vector2f pos);
	Vector2f getPosition() const;
	FloatRect getCollisionBox() const;
	CircleShape getShape() const;
	void setXVelocity(float xSpeed);
	void setYVelocity(float ySpeed);
	float getXVelocity() const;
	float getYVelocity() const;
	Text getPositionText();
	Sprite getSprite() const;

};

#endif
