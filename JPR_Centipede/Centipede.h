#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "CentipedeDirection.h"

class Centipede : public GameObject
{

protected:
	Centipede* next = NULL;
	Centipede* prev = NULL;
	Vector2f lastPos;
	CentipedeDirection dir = CentipedeDirection::Left;
	bool reversed = false;

	Centipede(const Centipede& obj) = delete;
	Centipede& operator=(const Centipede& obj) = delete;

	void sendCommandToNext(ObjectCommand* cmd);
	virtual void handleFinishedCommand() override;

public:
	Centipede();
	~Centipede();

	virtual void init(float xPos, float yPos) override;

	void setNext(Centipede* next);
	Centipede* getNext() const;

	void setPrev(Centipede* prev);
	Centipede* getPrev() const;

	void setDirection(CentipedeDirection dir);
	CentipedeDirection getDirection() const;

	void setReversed();
	void unsetReversed();
	bool isReversed() const;

};

#endif

