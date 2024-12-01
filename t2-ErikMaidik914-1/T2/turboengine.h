#pragma once
#include<string>
#include"engine.h"

using namespace std;

class TurboEngine :
	public Engine
{
private:
	//int turboPrice;
public:
	double getPrice() const override;
	string toString() const override;
};