#include "SoundManager.h"

SoundManager* SoundManager::instance = NULL;

SoundManager::SoundManager() {

	this->bufs = new SoundBuffer[128];

};

SoundManager::~SoundManager() {

	delete[] this->bufs;

};

SoundManager* SoundManager::getInstance() {

	if (!instance) {

		instance = new SoundManager();

	}

	return instance;

}

void SoundManager::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

	}

}

void SoundManager::loadFromFile(const char* filename) {

	cout << "Opening file list " << filename << endl;

	fstream f;
	f.open(filename);

	if (f.is_open()) {

		cout << "Opened file list " << filename << endl;

		int i = 0;
		while (!f.eof()) {

			char temp[256];
			f.getline(temp, 256);
			this->parseLine(temp, i);
			++i;

		}

	}
	else {

		cout << "Could not open file " << filename << endl;

	}

	f.close();

}

void SoundManager::parseLine(const char* str, int i) {

	stringstream ss;
	ss << "assets/sounds/" << str;
	this->bufs[i].loadFromFile(ss.str());
	cout << "Loaded file " << str << endl;

}

SoundBuffer SoundManager::get(int i) const {

	return this->bufs[i];

}