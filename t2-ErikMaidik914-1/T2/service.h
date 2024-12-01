#pragma once
#include<string>
#include<vector>
#include"engine.h"
#include"car.h"
using namespace std;

class Service
{
private:
	
public:
	void addCar(string bodyStyle, string engineType, int autonomy);
	vector<Car> showAll();
};