#pragma once
#include<string>
#include"domain.h"
#include<vector>

using namespace std;

class Repository
{
private:
	Tutorial domain;
	vector<Tutorial> allTutorials;
	vector<Tutorial> watchlist;
public:
	vector<Tutorial> getAll() const;
	bool addTutorial(Tutorial tutorial);
	bool removeTutorial(Tutorial tutorial);
	bool updateTutorial(Tutorial TutorialToUpdate, Tutorial updatedTutorial);
	int countTutorialsWithPresenter(const string& presenter) const;
	bool addTutorialToWatch(Tutorial tutorial);
	bool removeTutorialFromWatch(Tutorial tutorial);
	vector<Tutorial> getWatch() const;
	bool addTutorialSTL(Tutorial tutorial);
	bool removeTutorialSTL(Tutorial tutorial);
};