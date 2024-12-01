#include<string>
#include<sstream>
#include"turboengine.h"
using namespace std;

double TurboEngine::getPrice() const
{

	return this->basePrice+100;
}