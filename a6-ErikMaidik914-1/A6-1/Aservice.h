#pragma once
#include<string>
#include "repository.h"

using namespace std;

class Aservice
{
private:
	Repository repo;
public:

	bool addTutorial(string title, string presenter, Duration duration, int likes, string link);
	bool removeTutorial(string title, string presenter);
	bool updateTutorial(string title, string presenter, string newTitle, string newPresenter, Duration newDuration, int newLikes, string newLink);
	bool increaseLikes(string title, string presenter);
	vector<Tutorial> getAllTutorials() const;
	void initialiseRepository();
	Duration generateRandomDuration();
};

