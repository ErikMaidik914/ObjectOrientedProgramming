#include<string>
#include "repository.h"

using namespace std;

vector<Tutorial> Repository::getAll() const
{
	return allTutorials;
}

//bool Repository::addTutorialSTL(Tutorial tutorial)
//{//without stl functions
	//for (const auto& existingTutorial : allTutorials)
	//{
		//if (existingTutorial.getTitle() == tutorial.getTitle() && existingTutorial.getPresenter() == tutorial.getPresenter())
		//{
		//	return false; // Tutorial already exists
	//	}
	//}
	//allTutorials.push_back(tutorial);
//	return true; // Tutorial added successfully
//}

//bool Repository::removeTutorialSTL(Tutorial tutorial)
//{//without stl functions
	//for (int i = 0; i < allTutorials.size(); i++)
	//{
	//	if (allTutorials[i].getTitle() == tutorial.getTitle() && allTutorials[i].getPresenter() == tutorial.getPresenter()){
		//	allTutorials.erase(allTutorials.begin() + i);
		//	return true;
		//}
	//}
	// false;
//}

bool Repository::updateTutorial(Tutorial tutorialToUpdate, Tutorial updatedTutorial) {
	for (int i = 0; i < allTutorials.size(); i++) {
		if (allTutorials[i].getTitle() == tutorialToUpdate.getTitle() && allTutorials[i].getPresenter() == tutorialToUpdate.getPresenter()) {
			allTutorials[i] = updatedTutorial;
			return true;
		}
	}
	return false;
}
//user:


vector<Tutorial> Repository::getWatch() const
{
	return watchlist;
}

bool Repository::addTutorialToWatch(Tutorial tutorial)
{
	auto foundTutorial = find_if(watchlist.begin(), watchlist.end(),
		[&](const Tutorial& existingTutorial) {//lambda functions that captures the tutorial
			return existingTutorial.getTitle() == tutorial.getTitle() && existingTutorial.getPresenter() == tutorial.getPresenter();
		});

	if (foundTutorial != watchlist.end())
	{
		return false;
	}

	watchlist.push_back(tutorial);
	return true;
}

bool Repository::removeTutorialFromWatch(Tutorial tutorial)
{
	auto it = remove_if(watchlist.begin(), watchlist.end(),
		[&](const Tutorial& existingTutorial) {
			return existingTutorial.getTitle() == tutorial.getTitle() && existingTutorial.getPresenter() == tutorial.getPresenter();
		});

	if (it != watchlist.end())
	{
		watchlist.erase(it);
		return true;
	}

	return false;
}




bool Repository::addTutorial(Tutorial tutorial)
{
	auto foundTutorial = find_if(allTutorials.begin(), allTutorials.end(),
		[&](const Tutorial& existingTutorial) {//lambda functions that captures the tutorial
			return existingTutorial.getTitle() == tutorial.getTitle() && existingTutorial.getPresenter() == tutorial.getPresenter();
		});

	if (foundTutorial != allTutorials.end())
	{
		return false; 
	}

	allTutorials.push_back(tutorial);
	return true; 
}


bool Repository::removeTutorial(Tutorial tutorial)
{
	auto it = remove_if(allTutorials.begin(), allTutorials.end(),
		[&](const Tutorial& existingTutorial) {
			return existingTutorial.getTitle() == tutorial.getTitle() && existingTutorial.getPresenter() == tutorial.getPresenter();
		});

	if (it != allTutorials.end())
	{
		allTutorials.erase(it);
		return true; 
	}

	return false; 
}

