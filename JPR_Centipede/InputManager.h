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
	bool upActive = false;
	bool downActive = false;
	bool leftActive = false;
	bool rightActive = false;
	bool fireActive = false;

public:
	bool isUpPressed();
	void upPressed();
	bool isDownPressed();
	void downPressed();
	bool isLeftPressed();
	void leftPressed();
	bool isRightPressed();
	void rightPressed();
	bool isFirePressed();
	void firePressed();
	void update();

};

#endif

