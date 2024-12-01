#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Vegetable
{
private:
	string family;
	string name;
	string parts;
public:
	Vegetable() : family(""), name(""), parts("") {};
	Vegetable(string family, string name, string parts) : family(family), name(name), parts(parts) {};
	string getFamily() { return this->family; }
	string getName(){ return this->name; }
	string getParts(){ return this->parts; }

	friend istream& operator>>(istream& is, Vegetable& v);

	string toString();
};

