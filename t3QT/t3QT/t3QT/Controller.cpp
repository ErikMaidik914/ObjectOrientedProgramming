#include "Controller.h"
#include <algorithm>

bool sortByFirstLetterOfFamily( Vegetable& v1, Vegetable& v2)
{
	return v1.getFamily()[0] < v2.getFamily()[0];
}

vector<Vegetable> Controller::getAllVegetables()
{
	sort(this->allVegetables.begin(), this->allVegetables.end(), sortByFirstLetterOfFamily);
	return this->allVegetables;
}

vector<Vegetable> Controller::getAllVegetablesWithUniqueFamilies()
{
    vector<Vegetable> result;
    for (auto vegetable : this->allVegetables)
    {
		bool found = false;
        for (auto resultVegetable : result)
        {
            if (vegetable.getFamily() == resultVegetable.getFamily())
            {
				found = true;
				break;
			}
		}
		if (!found)
			result.push_back(vegetable);
	}
    sort(result.begin(), result.end(), sortByFirstLetterOfFamily);
	return result;
}




void Controller::readFromFile()
{
    ifstream inputFile(this->filename);
    if (!inputFile.is_open())
        cout << "The file could not be opened!";
    Vegetable currentVegetable;
    while (inputFile >> currentVegetable) {
        this->allVegetables.push_back(currentVegetable);
    }
    inputFile.close();
}