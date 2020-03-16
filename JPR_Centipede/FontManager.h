#ifndef FONTMANAGER_H
#define FONTMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;
using namespace std;

class FontManager
{

private:
	static FontManager* instance;
	vector<Font*> fonts;

	FontManager();
	FontManager(const FontManager& obj) = delete;
	~FontManager();
	FontManager& operator=(const FontManager& obj) = delete;

public:
	static FontManager* getInstance();
	static void resetInstance();
	Font* get(int i) const;

};

#endif

