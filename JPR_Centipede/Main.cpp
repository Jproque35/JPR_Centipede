// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Engine.h"
#include "GameObjectManager.h"
#include "GridManager.h"

using namespace sf;

int main()
{
	Engine engine;

	engine.start();

	/*
	GridManager gm(5, 5);

	for (int i = 0; i < gm.getHeight(); i++) {

		for (int j = 0; j < gm.getWidth(); j++) {

			if (i % 2 == 0) {

				gm.add("a", j, i);
				gm.add("b", j, i);
				gm.add("c", j, i);

			}
			else {

				gm.add("b", j, i);
				gm.add("c", j, i);
				gm.add("d", j, i);

			}

		}

	}

	//gm.swap(0, 0, 0, 1);

	for (int i = 0; i < gm.getHeight(); i++) {

		for (int j = 0; j < gm.getWidth(); j++) {

			cout << "(" << j << ", " << i << ") : ";

			vector<string> currList = gm.get(j, i);
			cout << currList.size();
			for (int k = 0; k < currList.size(); k++) {

				cout << currList[k];

			}

			cout << endl;

		}

		cout << endl;

	}

	gm.clear();

	for (int i = 0; i < gm.getHeight(); i++) {

		for (int j = 0; j < gm.getWidth(); j++) {

			cout << "(" << j << ", " << i << ") : ";

			vector<string> currList = gm.get(j, i);

			cout << currList.size();
			for (int k = 0; k < currList.size(); k++) {

				cout << currList[k];

			}

			cout << endl;

		}

		cout << endl;

	}*/

	return 0;

}