#include<string>
#include"Aservice.h"
#include"domain.h"

using namespace std;

bool Aservice::removeTutorial(string title, string presenter)
{

	Tutorial tutorial(title, presenter, Duration{ 0, 0 }, 0, "link");
	return repo.removeTutorial(tutorial);
}

bool Aservice::addTutorial(string title, string presenter, Duration duration, int likes, string link)
{
	Tutorial tutorial(title, presenter, duration, likes, link);
	return repo.addTutorial(tutorial);
}

vector<Tutorial> Aservice::getAllTutorials() const
{
    return repo.getAll();
}

void Aservice::initialiseRepository()
{
    Duration duration;

    duration = generateRandomDuration();
    addTutorial("C++ Tutorial for Beginners - Learn C++ in 1 Hour", "Programming with mosh", duration, 101, "https://www.youtube.com");

    duration = generateRandomDuration();
    addTutorial("C++ Developer Roadmap", "Fireship", duration, 101, "https://www.vimeo.com");

    duration = generateRandomDuration();
    addTutorial("Introducere în programare - tutorial C++ - cursul 1", "Videotutorial.ro", duration, 7600, "https://www.youtube.com");

    duration = generateRandomDuration();
    addTutorial("C++ - From Zero To Hero", "Academind", duration, 12345, "https://www.vimeo.com");

    duration = generateRandomDuration();
    addTutorial("C++ Full Course for free", "BroCode", duration, 40000, "https://www.youtube.com");

    duration = generateRandomDuration();
    addTutorial("C++ STRINGS (C++ Zero to Hero - Part 5)", "Zero to Hero", duration, 1234, "https://www.youtube.com");

    duration = generateRandomDuration();
    addTutorial("C++ in 100 Seconds", "Fireship", duration, 52000, "https://www.youtube.com");

    duration = generateRandomDuration();
    addTutorial("How to master C++", "CS Dojo", duration, 100596, "https://www.odysee.com");

    duration = generateRandomDuration();
    addTutorial("Full Course - OOP in C++", "FreeCodeCamp", duration, 60000, "https://www.youtube.com");

    duration = generateRandomDuration();
    addTutorial("Introduction in C++", "BroCode", duration, 101, "https://www.youtube.com");
}

Duration Aservice::generateRandomDuration()
{
    Duration duration;
    duration.seconds = rand() % 60;
    duration.minutes = rand() % 60;
    return duration;
}

bool Aservice:: updateTutorial(string title, string presenter, string newTitle, string newPresenter, Duration newDuration, int newLikes, string newLink)
{
    Tutorial tutorialToUpdate(title, presenter, Duration{ 0, 0 }, 0, "");
    Tutorial updatedTutorial(newTitle, newPresenter, newDuration, newLikes, newLink);
    return repo.updateTutorial(tutorialToUpdate, updatedTutorial);
}

bool Aservice::increaseLikes(string title, string presenter) 
{
    vector<Tutorial> allTutorials = repo.getAll();
    for (auto& tutorial : allTutorials) {
        if (tutorial.getTitle() == title && tutorial.getPresenter() == presenter) {
            tutorial.setLikes(tutorial.getLikes() + 1);
            return true;
        }
    }
    return false;
}
