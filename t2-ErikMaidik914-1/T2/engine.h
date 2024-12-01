#pragma once
#include<string>

using namespace std;

class Engine
{
protected:
	double basePrice;
public:
	Engine(double basePrice) : basePrice{ basePrice } {};
	virtual double getPrice() const;
	virtual string toString() const;
};