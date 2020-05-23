#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#pragma once
#include "Screen.h"

class GameObject;

class GameScreen :
	public Screen
{

private:

	Text hudText;

	GameScreen(const GameScreen& obj) = delete;
	GameScreen& operator=(const GameScreen& obj) = delete;

	void reset();
	void executeObjectEventListeners(float elapsedTime);
	void drawShape(RenderWindow& window, CircleShape shape);
	void drawSprite(RenderWindow& window, Sprite spr);
	void drawBackgroundTile(RenderWindow& window, Sprite img);
	void drawText(RenderWindow& window, const Text& drawable);
	void processObject(GameObject* obj);

protected:
	void input(float dtAsSecods);
	void update(float dtAsSeconds);
	void draw();

public:
	GameScreen();
	~GameScreen();

	virtual void enterScreen(ScreenType originScreen) override;
	virtual void exitScreen(ScreenType destScreen) override;

};

#endif