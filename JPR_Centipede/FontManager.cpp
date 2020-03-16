#include "FontManager.h"

FontManager* FontManager::instance = NULL;

FontManager::FontManager() {

	Font* f = new Font();

	f->loadFromFile("game_over.ttf");

	this->fonts.push_back(f);

}

FontManager::~FontManager() {

	for (int i = 0; i < this->fonts.size(); ++i) {

		if (this->fonts[i] != NULL) {

			delete(this->fonts[i]);
			this->fonts[i] = NULL;

		}
	}

}

FontManager* FontManager::getInstance() {

	if (!instance) {

		instance = new FontManager();

	}

	return instance;

}

void FontManager::resetInstance() {

	if (instance != NULL) {

		delete(instance);
		instance = NULL;

	}

}

Font* FontManager::get(int i) const {

	return this->fonts[i];

}