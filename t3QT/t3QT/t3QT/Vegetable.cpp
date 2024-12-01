#include "Vegetable.h"
#include<sstream>
#include<iostream>
#include<vector>

string Vegetable::toString()
{
	stringstream result;
	result << "Family: " << this->family << ";";
		//<< "Name: " << this->name << ";"
		//<< "Parts: " << this->parts;
	return result.str();
}

istream& operator>>(istream& is, Vegetable& v)
{
	string line;
	getline(is, line);


	stringstream ss(line);
	string token;
	vector<string> tokens;

	while (getline(ss, token, ';'))
		tokens.push_back(token);

	if (tokens.size() != 3)
		return is;

	v.family = tokens[0];
	//v.name = tokens[1];
	//v.parts = tokens[2];

	return is;
}
