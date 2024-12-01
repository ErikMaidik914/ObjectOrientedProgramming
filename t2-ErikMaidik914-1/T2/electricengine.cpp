#include<string>
#include<sstream>
#include"electricengine.h"
using namespace std;

double ElectricEngine::getPrice() const
{
	return this->basePrice + this->autonomy*0,01;
}