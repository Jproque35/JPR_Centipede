#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager
{

private:
	Keyboard::Key upKey = Keyboard::W;
	Keyboard::Key downKey = Keyboard::S;
	Keyboard::Key leftKey = Keyboard::A;
	Keyboard::Key rightKey = Keyboard::D;
	Keyboard::Key fireKey = Keyboard::Space;
	bool upPressed = false;
	bool downPressed = false;
	bool leftPressed = false;
	bool rightPressed = false;
	bool firePressed = false;

public:
	bool isUpPressed();
	void checkUpPressed();
	bool isDownPressed();
	void checkDownPressed();
	bool isLeftPressed();
	void checkLeftPressed();
	bool isRightPressed();
	void checkRightPressed();
	bool isFirePressed();
	void checkFirePressed();
	void update();

};

#endif

