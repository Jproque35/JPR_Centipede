#include "Engine.h"

void Engine::update(float dtAsSeconds) {

	//cout << "Updating objects..." << endl;

	this->buildGridState();

	for (int i = 0; i < this->objectControllers.size(); i++) {

		//cout << "Updating object in slot " << i << endl;

		if(this->objectControllers[i] != NULL) {

			//this->centipedeControllers[i]->checkCollisionWithObjects(this->getCollisionObjects(this->centipedeControllers[i]->getData()));
			this->objectControllers[i]->checkCollisionWithObjects(this->getCollisionObjects(this->objectControllers[i]->getData()));
			this->objectControllers[i]->update(dtAsSeconds);

			//cout << "Object in slot " << i << " has been successfully updated." << endl;

		}
		else {

			//cout << "Object in slot " << i << " was not updated." << endl;

		}

	}

}

vector<vector<GameObject*>> Engine::getCollisionObjects(GameObject* obj) {

	int xLo = floor(obj->getPosition().x);
	int yLo = floor(obj->getPosition().y);
	float diameter = 2 * obj->getShape().getRadius();
	int xHi = floor(obj->getPosition().x + diameter);
	int yHi = floor(obj->getPosition().y + diameter);

	vector<vector<GameObject*>> desire;

	for (int i = xLo; i < xHi; i++) {

		for (int j = yLo; j < yHi; j++) {

			desire.push_back(this->grid->get(i, j));

		}
	}

	return desire;
}