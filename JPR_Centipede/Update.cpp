#include "Engine.h"

void Engine::update(float dtAsSeconds) {

	//cout << "Updating objects..." << endl;
	this->em->update(dtAsSeconds);
	this->gm->updateAll(dtAsSeconds);

}