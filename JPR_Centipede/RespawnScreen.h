#ifndef RESPAWNSCREEN_H
#define RESPAWNSCREEN_H
#pragma once
#include "Screen.h"

class RespawnScreen :
	public Screen
{

private:
	int red;
	int green;
	int blue;
	float counter = 0.0f;

protected:
	virtual void input(float dtAsSecods) override;
	virtual void update(float dtAsSeconds) override;
	virtual void draw() override;

	RespawnScreen(const RespawnScreen& obj) = delete;
	RespawnScreen& operator=(const RespawnScreen& obj) = delete;

public:
	RespawnScreen();
	~RespawnScreen();
	virtual void init(RenderWindow& w) override;

};

#endif
