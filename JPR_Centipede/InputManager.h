#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class InputManager
{

private:
	static InputManager* instance;
	Keyboard::Key upKey = Keyboard::W;
	Keyboard::Key downKey = Keyboard::S;
	Keyboard::Key leftKey = Keyboard::A;
	Keyboard::Key rightKey = Keyboard::D;
	Keyboard::Key fireKey = Keyboard::Space;
	Keyboard::Key debugKey = Keyboard::F10;
	bool upActive = false;
	bool downActive = false;
	bool leftActive = false;
	bool rightActive = false;
	bool fireActive = false;
	bool fireLock = false;
	bool debugActive = false;
	bool debugLock = false;

	InputManager() {};
	InputManager(const InputManager& obj) = delete;
	~InputManager();
	InputManager& operator=(const InputManager& obj) = delete;

public:
	static InputManager* getInstance();
	static void resetInstance();
	bool isUpPressed() const;
	void upPressed();
	bool isDownPressed() const;
	void downPressed();
	bool isLeftPressed() const;
	void leftPressed();
	bool isRightPressed() const;
	void rightPressed();
	bool isFirePressed() const;
	void firePressed();
	bool isDebugActive() const;
	void debugPressed();
	void update();

};

#endif

