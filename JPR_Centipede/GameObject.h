#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateTypes.h"
#include "ObjectType.h"

using namespace sf;
using namespace std;

class GameObjectState;
class GameEventListener;

class GameObject
{

protected:
	GameObjectState* currState;
	unordered_map<StateType, GameObjectState*> states;
	ObjectType type = ObjectType::Generic;
	Vector2f pos;
	CircleShape shape;
	Sprite spr;
	float xSpeed = 0.0f, ySpeed = 0.0f;
	Text posText;
	int id = -1;

	void deleteStates();
	void assignmentAux(const GameObject& obj);

public:
	GameObject();

	virtual void init(float xPos, float yPos) = 0;

	ObjectType getType() const;

	void setStateType(StateType type);
	StateType getStateType() const;
	GameObjectState* getState() const;

	void setX(float xPos);
	void setY(float yPos);
	float getX() const;
	float getY() const;
	float getYSpeed() const;
	float getXSpeed() const;

	Vector2f getPosition() const;
	void setShapePosition(float xPos, float yPos);
	CircleShape getShape() const;
	void setSpritePosition(float xPos, float yPos);
	Sprite getSprite() const;
	void update(float elapsedTime);

	void setId(int i);
	int getId() const;


};

#endif

