#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#pragma once
#include "GameObject.h"
#include "GenericState.h"
#include "CentipedeData.h"

enum class CentipedeType { Head, Body };

class Centipede : public GameObject
{

private:
	CentipedeType type = CentipedeType::Head;
	CentipedeData* context;

	void preUpdate(float elapsedTime);
	void postUpdate(float elapsedTime);

public:
	Centipede(float initX, float initY);
	Centipede(const Centipede& obj);
	~Centipede();
	Centipede& operator=(const Centipede& obj);

	ObjectData* getData();
	CentipedeType getCentipedeType();
	void setCentipedeType(CentipedeType type);
	void setNext(Centipede* next);
	void setPrev(Centipede* prev);

};

#endif

