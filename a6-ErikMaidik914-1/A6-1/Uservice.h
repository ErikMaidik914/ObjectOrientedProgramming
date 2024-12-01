#pragma once
#include<string>
#include "repository.h"

using namespace std;

class Uservice
{
private:
	Repository repo;
public:

	bool addTutorialToWatchlist(Tutorial tutorialToAdd);
	bool removeTutorialFromWatchlist(string title, string presenter);
	vector<Tutorial> getTutorialsOfPresenter(vector<Tutorial> allTutorials, string presenter);
	vector<Tutorial> getWatchlist() const;
};