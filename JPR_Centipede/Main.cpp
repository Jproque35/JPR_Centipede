// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "GameObjectManager.h"

using namespace sf;

int main()
{
	Engine* e = Engine::getInstance();

	e->start();

	Engine::resetInstance();

	return 0;

}