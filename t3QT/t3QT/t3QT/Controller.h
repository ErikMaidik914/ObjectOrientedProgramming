#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "Vegetable.h"

class Controller
{
private:
	vector<Vegetable>allVegetables;
	string filename;

	public:
		Controller(string filename, vector<Vegetable> initialVegetables = {}) : filename{ filename }, allVegetables{ initialVegetables }
		{
			this->readFromFile();
		}
	vector<Vegetable> getAllVegetables();
	vector<Vegetable> getAllVegetablesWithUniqueFamilies();
	void readFromFile();
};

