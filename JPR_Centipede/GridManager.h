#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
#pragma once
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class GridManager
{

private:
	int width = 0;
	int height = 0;
	string* objs;
	int getKey(int x, int y);

public:
	GridManager(int width, int height);
	//~GridManager();
	int getWidth();
	int getHeight();
	void swap(int x0, int y0, int x1, int y1);
	void add(string s, int x, int y);
	void erase(int x, int y);
	string get(int x, int y);


};

#endif

