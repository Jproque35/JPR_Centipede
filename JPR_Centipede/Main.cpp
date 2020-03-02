// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "GameObjectManager.h"
#include "GridManager.h"

using namespace sf;

int main()
{
	Engine* e = new Engine();

	e->start();

	delete(e);

	return 0;

}