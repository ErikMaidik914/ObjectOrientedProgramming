#pragma once
#include<string>
#include"engine.h"
#include<vector>

using namespace std;

class Car
{
private:
	string bodyStyle;
	vector<Car> allCars;
public:
	double computePrice();
	void addCar();
	void showAll();
};