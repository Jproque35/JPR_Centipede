#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateTypes.h"
#include "ObjectType.h"
#include <queue>
#include <iostream>

using namespace sf;
using namespace std;

class GameObjectState;
class GameEventListener;
class ObjectCommand;

class GameObject
{

protected:
	GameObjectState* currState = NULL;
	unordered_map<StateType, GameObjectState*> states;
	ObjectType type = ObjectType::Generic;
	Vector2f pos;
	CircleShape shape;
	Sprite spr;
	float xSpeed = 0.0f, ySpeed = 0.0f;
	Text posText;
	int id = -1;
	queue<ObjectCommand*> commands;

	void assignmentAux(const GameObject& obj);

	virtual void handleFinishedCommand();

private:
	//every game object is unique, we do not want to copy them so we make copy constructor private
	GameObject(const GameObject& obj) = delete;

	//same reasoning, every game object is unique and we do not want to copy them
	GameObject& operator=(const GameObject& obj) = delete;

public:
	GameObject();
	virtual ~GameObject();

	virtual void init(float xPos, float yPos);

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

	virtual void executeCommand(float elapsedTime);
	void addCommand(ObjectCommand* cmd);
	size_t getCommandsSize() const;
	void clearCommands();

	Vector2f getPosition() const;
	void setShapePosition(float xPos, float yPos);
	CircleShape getShape() const;
	void setSpritePosition(float xPos, float yPos);
	Sprite getSprite() const;
	void update(float elapsedTime);

	void setId(int i);
	int getId() const;

	FloatRect getCollisionBox() const;


};

#endif

