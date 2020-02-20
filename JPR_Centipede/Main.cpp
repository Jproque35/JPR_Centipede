// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "GameObjectManager.h"
#include "GridManager.h"

using namespace sf;

int main()
{
	//Engine engine;

	//engine.start();

	GridManager gm(5, 5);

	for (int i = 0; i < gm.getHeight(); i++) {

		for (int j = 0; j < gm.getWidth(); j++) {

			if (i % 2 == 0) {

				gm.add("a", i, j);

			}
			else {

				gm.add("b", i, j);

			}

		}

	}

	gm.swap(0, 0, 1, 0);

	for (int i = 0; i < gm.getHeight(); i++) {

		for (int j = 0; j < gm.getWidth(); j++) {

			cout << "(" << i << ", " << j << ")" << gm.get(i, j) << " ";

		}

		cout << endl;

	}

	return 0;

}