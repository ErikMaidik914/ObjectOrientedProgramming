#include "test.h"
#include<string>
#include <assert.h>
#include "Repository.h"
#include "Aservice.h"
#include "Uservice.h"
#include "domain.h"

using namespace std;

void Tests::testDomain()
{

    Duration duration = { 5, 30 };
    Tutorial tutorial("Test Title", "Test Presenter", duration, 100, "https://test.com");

    assert(tutorial.getTitle() == "Test Title");
    assert(tutorial.getPresenter() == "Test Presenter");
    assert(tutorial.getDuration().minutes == 5);
    assert(tutorial.getDuration().seconds == 30);
    assert(tutorial.getLikes() == 100);
    assert(tutorial.getLink() == "https://test.com");

    tutorial.setTitle("New Title");
    tutorial.setPresenter("New Presenter");
    Duration newDuration = { 2, 45 };
    tutorial.setDuration(newDuration);
    tutorial.setLikes(200);
    tutorial.setLink("https://newlink.com");
    assert(tutorial.getTitle() == "New Title");
    assert(tutorial.getPresenter() == "New Presenter");
    assert(tutorial.getDuration().minutes == 2);
    assert(tutorial.getDuration().seconds == 45);
    assert(tutorial.getLikes() == 200);
    assert(tutorial.getLink() == "https://newlink.com");
}


void Tests::testRepository()
{
    Repository repository;
    Tutorial tutorial1("Title 1", "Presenter 1", { 10, 30 }, 50, "https://example.com/1");
    Tutorial tutorial2("Title 2", "Presenter 2", { 5, 0 }, 20, "https://example.com/2");

    // getAll
    repository.addTutorial(tutorial1);
    repository.addTutorial(tutorial2);

    std::vector<Tutorial> allTutorials = repository.getAll();
    assert(allTutorials.size() == 2);
    assert(allTutorials[0].getTitle() == "Title 1");
    assert(allTutorials[0].getPresenter() == "Presenter 1");
    assert(allTutorials[0].getDuration().minutes == 10);
    assert(allTutorials[0].getDuration().seconds == 30);
    assert(allTutorials[0].getLikes() == 50);
    assert(allTutorials[0].getLink() == "https://example.com/1");
    assert(allTutorials[1].getTitle() == "Title 2");
    assert(allTutorials[1].getPresenter() == "Presenter 2");
    assert(allTutorials[1].getDuration().minutes == 5);
    assert(allTutorials[1].getDuration().seconds == 0);
    assert(allTutorials[1].getLikes() == 20);
    assert(allTutorials[1].getLink() == "https://example.com/2");

    // addTutorial
    Tutorial tutorial3("Title 3", "Presenter 3", { 8, 15 }, 30, "https://example.com/3");
    bool added = repository.addTutorial(tutorial3);
    assert(added);
    allTutorials = repository.getAll();
    assert(allTutorials.size() == 3);
    assert(allTutorials[2].getTitle() == "Title 3");
    assert(allTutorials[2].getPresenter() == "Presenter 3");
    assert(allTutorials[2].getDuration().minutes == 8);
    assert(allTutorials[2].getDuration().seconds == 15);
    assert(allTutorials[2].getLikes() == 30);
    assert(allTutorials[2].getLink() == "https://example.com/3");

    // duplicate
    added = repository.addTutorial(tutorial1);
    assert(!added);

    // removeTutorial
    bool removed = repository.removeTutorial(tutorial2);
    assert(removed);
    allTutorials = repository.getAll();
    assert(allTutorials.size() == 2);

    // non-existent tutorial
    removed = repository.removeTutorial(tutorial2);
    assert(!removed);

    // updateTutorial
    Tutorial updatedTutorial("Updated Title", "Updated Presenter", { 15, 0 }, 100, "https://example.com/updated");
    bool updated = repository.updateTutorial(tutorial1, updatedTutorial);
    assert(updated);
    allTutorials = repository.getAll();
    assert(allTutorials.size() == 2);
    assert(allTutorials[0].getTitle() == "Updated Title");
    assert(allTutorials[0].getPresenter() == "Updated Presenter");
    assert(allTutorials[0].getDuration().minutes == 15);
    assert(allTutorials[0].getDuration().seconds == 0);
    assert(allTutorials[0].getLikes() == 100);
    assert(allTutorials[0].getLink() == "https://example.com/updated");

    // non-existent tutorial
    Tutorial nonExistentTutorial("Non-existent Title", "Non-existent Presenter", { 0, 0 }, 0, "https://example.com/nonexistent");
    updated = repository.updateTutorial(nonExistentTutorial, updatedTutorial);
    assert(!updated);

    // getWatch
    std::vector<Tutorial> watchlist = repository.getWatch();
    assert(watchlist.size() == 0);

    // addTutorialToWatch
    bool addedToWatch = repository.addTutorialToWatch(tutorial1);
    assert(addedToWatch);
    watchlist = repository.getWatch();
    assert(watchlist.size() == 1);
    assert(watchlist[0].getTitle() == "Title 1");
    assert(watchlist[0].getPresenter() == "Presenter 1");
    assert(watchlist[0].getDuration().minutes == 10);
    assert(watchlist[0].getDuration().seconds == 30);
    assert(watchlist[0].getLikes() == 50);
    assert(watchlist[0].getLink() == "https://example.com/1");

    // duplicate in watchlist
    addedToWatch = repository.addTutorialToWatch(tutorial1);
    assert(!addedToWatch);

    // removeTutorialFromWatch
    bool removedFromWatch = repository.removeTutorialFromWatch(tutorial1);
    assert(removedFromWatch);
    watchlist = repository.getWatch();
    assert(watchlist.size() == 0);

    // non-existent tutorial in watchlist
    removedFromWatch = repository.removeTutorialFromWatch(tutorial1);
    assert(!removedFromWatch);
}



void Tests::testAservice()
{
    Aservice aservice;

    // Initialise repository
    aservice.initialiseRepository();

    // Test getAllTutorials
    aservice.addTutorial("Title 1", "Presenter 1", { 10, 30 }, 50, "https://example.com/1");
    aservice.addTutorial("Title 2", "Presenter 2", { 5, 0 }, 20, "https://example.com/2");

    std::vector<Tutorial> allTutorials = aservice.getAllTutorials();
    assert(allTutorials.size() == 12);
    assert(allTutorials[10].getTitle() == "Title 1");
    assert(allTutorials[10].getPresenter() == "Presenter 1");
    assert(allTutorials[10].getDuration().minutes == 10);
    assert(allTutorials[10].getDuration().seconds == 30);
    assert(allTutorials[10].getLikes() == 50);
    assert(allTutorials[10].getLink() == "https://example.com/1");
    assert(allTutorials[11].getTitle() == "Title 2");
    assert(allTutorials[11].getPresenter() == "Presenter 2");
    assert(allTutorials[11].getDuration().minutes == 5);
    assert(allTutorials[11].getDuration().seconds == 0);
    assert(allTutorials[11].getLikes() == 20);
    assert(allTutorials[11].getLink() == "https://example.com/2");

    // Test addTutorial
    Duration duration = { 8, 15 };
    bool added = aservice.addTutorial("Title 3", "Presenter 3", duration, 30, "https://example.com/3");
    assert(added);
    allTutorials = aservice.getAllTutorials();
    assert(allTutorials.size() == 13);
    assert(allTutorials[12].getTitle() == "Title 3");
    assert(allTutorials[12].getPresenter() == "Presenter 3");
    assert(allTutorials[12].getDuration().minutes == 8);
    assert(allTutorials[12].getDuration().seconds == 15);
    assert(allTutorials[12].getLikes() == 30);
    assert(allTutorials[12].getLink() == "https://example.com/3");

    // duplicate
    added = aservice.addTutorial("Title 1", "Presenter 1", { 0, 0 }, 0, "");
    assert(!added);

    // removeTutorial
    bool removed = aservice.removeTutorial("Title 2", "Presenter 2");
    assert(removed);
    allTutorials = aservice.getAllTutorials();
    assert(allTutorials.size() == 12);

    // non-existent tutorial
    removed = aservice.removeTutorial("Title 2", "Presenter 2");
    assert(!removed);

    // updateTutorial
    bool updated = aservice.updateTutorial("Title 1", "Presenter 1", "Updated Title", "Updated Presenter", { 15, 0 }, 100, "https://example.com/updated");
    assert(updated);
    allTutorials = aservice.getAllTutorials();
    assert(allTutorials.size() == 12);
    assert(allTutorials[10].getTitle() == "Updated Title");
    assert(allTutorials[10].getPresenter() == "Updated Presenter");
    assert(allTutorials[10].getDuration().minutes == 15);
    assert(allTutorials[10].getDuration().seconds == 0);
    assert(allTutorials[10].getLikes() == 100);
    assert(allTutorials[10].getLink() == "https://example.com/updated");

    // non-existent tutorial
    updated = aservice.updateTutorial("Non-existent Title", "Non-existent Presenter", "Updated Title", "Updated Presenter", { 0, 0 }, 0, "");
    assert(!updated);

    // increaseLikes
    bool increased = aservice.increaseLikes("Updated Title", "Updated Presenter");
    assert(increased);
    allTutorials = aservice.getAllTutorials();
    assert(allTutorials[0].getLikes() == 101);

}

void Tests::testUservice()
{
    Uservice uservice;

    // Test addTutorialToWatchlist
    Tutorial tutorial("Title 1", "Presenter 1", { 10, 30 }, 50, "https://example.com/1");
    bool addedToWatchlist = uservice.addTutorialToWatchlist(tutorial);
    assert(addedToWatchlist);

    // Test getWatchlist
    std::vector<Tutorial> watchlist = uservice.getWatchlist();
    assert(watchlist.size() == 1);
    assert(watchlist[0].getTitle() == "Title 1");
    assert(watchlist[0].getPresenter() == "Presenter 1");
    assert(watchlist[0].getDuration().minutes == 10);
    assert(watchlist[0].getDuration().seconds == 30);
    assert(watchlist[0].getLikes() == 50);
    assert(watchlist[0].getLink() == "https://example.com/1");

    // Test removeTutorialFromWatchlist
    bool removedFromWatchlist = uservice.removeTutorialFromWatchlist("Title 1", "Presenter 1");
    assert(removedFromWatchlist);

    // Verify the watchlist is now empty
    watchlist = uservice.getWatchlist();
    assert(watchlist.empty());

    // Test getTutorialsOfPresenter
    std::vector<Tutorial> allTutorials; // Assuming you have a vector of all tutorials available
    allTutorials.push_back(Tutorial("Title 2", "Presenter 2", { 5, 0 }, 20, "https://example.com/2"));
    allTutorials.push_back(Tutorial("Title 3", "Presenter 1", { 8, 0 }, 15, "https://example.com/3"));
    std::vector<Tutorial> tutorialsOfPresenter = uservice.getTutorialsOfPresenter(allTutorials, "Presenter 1");
    assert(tutorialsOfPresenter.size() == 1);
    assert(tutorialsOfPresenter[0].getTitle() == "Title 3");
    assert(tutorialsOfPresenter[0].getPresenter() == "Presenter 1");
    assert(tutorialsOfPresenter[0].getDuration().minutes == 8);
    assert(tutorialsOfPresenter[0].getDuration().seconds == 0);
    assert(tutorialsOfPresenter[0].getLikes() == 15);
    assert(tutorialsOfPresenter[0].getLink() == "https://example.com/3");
}