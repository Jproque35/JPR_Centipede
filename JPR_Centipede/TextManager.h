#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

using namespace sf;
using namespace std;

enum class TextType {

	ScoreText,
	RespawnText,
	GameOverText,
	StartText,
	Unknown

};

class TextManager {

private:
	static TextManager* instance;
	unordered_map<TextType, Text*> texts;

	TextManager();
	~TextManager();
	TextManager(const TextManager& obj) = delete;
	TextManager& operator=(const TextManager& obj) = delete;

public:
	static TextManager* getInstance();
	static void resetInstance();
	void add( TextType type, Text* newText );
	Text* get(TextType type) const;

};

#endif
