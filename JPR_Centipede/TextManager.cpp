#include "TextManager.h"

TextManager* TextManager::instance = NULL;

TextManager::TextManager() {}

TextManager::~TextManager() {

	for (auto it = this->txts.begin(); it != this->txts.end(); ++it) {

		delete(it->second);

	}

}

TextManager* TextManager::getInstance() {


	if (!instance) {

		instance = new TextManager();

	}

	return instance;
}

void TextManager::resetInstance() {

	if (instance) {

		delete(instance);
		instance = NULL;

	}

}

void TextManager::add(TextType type, Text* newText) {

	this->txts[type] = newText;

}