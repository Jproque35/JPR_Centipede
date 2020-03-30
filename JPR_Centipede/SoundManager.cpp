#include "SoundManager.h"

SoundManager* SoundManager::instance = NULL;

SoundManager::SoundManager() {

	this->bufs.resize(128);

	for (int i = 0; i < this->bufs.size(); ++i) {

		this->bufs[i] = NULL;

	}

}

SoundManager::~SoundManager() {

	for (int i = 0; i < this->bufs.size(); ++i) {


		if (this->bufs[i] != NULL) {

			delete(this->bufs[i]);
			this->bufs[i] = NULL;

		}

	}

}

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

inline void SoundManager::parseLine(const char* str, int i) {

	stringstream ss;
	ss << "assets/sounds/" << str;
	this->bufs[i] = new SoundBuffer();
	this->bufs[i]->loadFromFile(ss.str());
	cout << "Loaded file " << str << " into slot " << i << endl;

}

SoundBuffer* SoundManager::get(int i) const {

	return this->bufs[i];

}