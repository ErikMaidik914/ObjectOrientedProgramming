#include<string>
#include"Uservice.h"

using namespace std;

bool Uservice::removeTutorialFromWatchlist(string title, string presenter)
{

	Tutorial tutorial(title, presenter, Duration{ 0, 0 }, 0, "link");
	return repo.removeTutorialFromWatch(tutorial);
}

bool Uservice::addTutorialToWatchlist(Tutorial tutorial)
{
	return repo.addTutorialToWatch(tutorial);
}

vector<Tutorial> Uservice::getWatchlist() const
{
	return repo.getWatch();
}

vector<Tutorial> Uservice::getTutorialsOfPresenter(vector<Tutorial> allTutorials, string presenter) {
    vector<Tutorial> tutorialsOfPresenter;

    for (const auto& tutorial : allTutorials) {
        if (tutorial.getPresenter() == presenter) {
            tutorialsOfPresenter.push_back(tutorial);
        }
    }

    return tutorialsOfPresenter;
}
