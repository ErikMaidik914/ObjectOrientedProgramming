#pragma once
#include<string>
#include"engine.h"

using namespace std;

class ElectricEngine :
	public Engine
{
private:
	int autonomy;
	//int electricPrice;
public:
	ElectricEngine(int autonomy) : autonomy{ autonomy } {
		ElectricEngine* engine1 = new ElectricEngine(3000);
		ElectricEngine* engine2 = new ElectricEngine(2000);
		ElectricEngine* engine3 = new ElectricEngine(1000);

	};

	double getPrice() const override;
	string toString() const override;
	
};