#include "TextManager.h"

TextManager* TextManager::instance = NULL;

TextManager::TextManager() {}

TextManager::~TextManager() {

	for (auto it = this->texts.begin(); it != this->texts.end(); ++it) {

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

void TextManager::add(TextType type, Text* const newText) {

	this->texts[type] = newText;

}

Text* TextManager::get(TextType type) const {

	return this->texts.at(type);

}