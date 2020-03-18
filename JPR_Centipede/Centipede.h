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

public:
	Centipede(float initX, float initY);
	Centipede(const Centipede& obj);
	~Centipede();
	Centipede& operator=(const Centipede& obj);

	void init(float xPos, float yPos);
	ObjectData* getData() const;
	CentipedeType getCentipedeType()const;
	void setCentipedeType(CentipedeType type);
	void update(float elapsedTime);

};

#endif

