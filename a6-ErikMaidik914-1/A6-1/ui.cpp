#include<string>
#include"ui.h"
#include<vector>
#include<iostream>

using namespace std;
#define ADDTUTORIAL 1
#define REMOVETUTORIAL 2
#define UPDATETUTORIAL 3
#define DISPLAYALLTUTORIALS 4
#define SEARCH 5
#define REMOVEFROMWATCH 6
#define DISPLAYWATCH 7
#define END 8
#define ENDU 9

void Ui::run()
{

	cout << "Welcome to Master C++\n" << endl;
	cout << "TESTS RAN SUCCESSFULY\n\n" << endl;
	cout << "CHOOSE YOUR MODE (administrator/user)\n" << "Type 'exit' to close app\n\n";
	string accessMode;
	while (true)
	{
		cout << "Enter mode: ";
		cin >> accessMode;
		if (accessMode.compare("administrator") == 0)
			administratorMode();
		else if (accessMode.compare("user") == 0)
			userMode();
		else if (accessMode.compare("exit") == 0)
		{
			cout << "Application exited successfully!\n";
			return;
		}
		else
			cout << "\nInvalid!    TYPE ONLY:administrator/user/exit\n\n";
	}
}

void Ui::printAdministratorMenu()
{
	cout << "\nADMINISTARTOR MODE ACTIVATED!\n\n";
	cout << "1. Add a tutorial\n";
	cout << "2. Remove a tutorial\n";
	cout << "3. Update a tutorial\n";
	cout << "4. Display all tutorials\n";
	cout << "0. Exit administrator mode\n";

}

void Ui::administratorMode()
{
	int optionChosen;
	while (true)
	{
		printAdministratorMenu();
		cout << "\nYOUR CHOICE: ";
		cin >> optionChosen;

		switch (optionChosen)
		{
		case ADDTUTORIAL:
			addTutorial();
			break;
		case REMOVETUTORIAL:
			removeTutorial();
			break;
		case UPDATETUTORIAL:
			updateTutorial();
			break;
		case DISPLAYALLTUTORIALS:
			displayAllTutorials();
			break;
		case END:
			cout << endl;
			return;
		default:
			cout << "\nInvalid input!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}

void Ui::printUserMenu()
{
	cout << "\nUSER MODE ACTIVATED!\n\n";
	cout << "1. Search tutorials\n";
	cout << "2. Remove tutorial from watchlist\n";
	cout << "3. Display watchlist\n";
	cout << "0. Exit user mode\n";
}

void Ui::userMode()
{
	int optionChosen;

	while (true)
	{
		printUserMenu();
		cout << "\nYOUR CHOICE: ";
		cin >> optionChosen;
		if (cin.fail() || optionChosen < 0) {
			cout << "\nInvalid input! Please enter a valid option.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch (optionChosen)
		{
		case SEARCH:
			searchTutorialsByPresenter();
			break;
		case REMOVEFROMWATCH:
			removeTutorialFromWatchlist();
			break;
		case DISPLAYWATCH:
			displayWatchlist();
			break;
		case ENDU:
			cout << endl;
			return;
		default:
			cout << "\nInvalid option!\n\n";
			break;
		}
	}
}
//ADMIN
void Ui::addTutorial()
{

	int likes;
	string title, presenter, link;
	Duration duration{ 0,0 };
	cout << "title: ";
	cin >> title;
	cout << "presenter: ";
	cin >> presenter;
	cout << "Tutorial duration:\n";
	cout << "Minutes: ";
	cin >> duration.minutes;
	cout << "Seconds: ";
	cin >> duration.seconds;
	cout << "likes: ";
	cin >> likes;
	cout << "link: ";
	cin >> link;
	if (aservice.addTutorial(title, presenter, duration, likes, link))
	{
		cout << "ADDED";
	}
	else
		cout << "Cant add duplicate";
}

void Ui::removeTutorial()
{
	string title, presenter;

	cout << "Enter the title of the tutorial to remove: ";
	cin.ignore();
	getline(cin, title);

	cout << "Enter the presenter of the tutorial to remove: ";
	getline(cin, presenter);

	if (aservice.removeTutorial(title, presenter))
	{
		cout << "Tutorial removed successfully." << endl;
	}
	else
	{
		cout << "Failed to remove the tutorial. Either it doesn't exist or the provided title/presenter is incorrect." << endl;
	}
}

void Ui::updateTutorial()
{
	string title, presenter;
	string newTitle, newPresenter, newLink;
	int newLikes;
	Duration newDuration{ 0, 0 };

	cout << "Enter the title of the tutorial to update: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter the presenter of the tutorial to update: ";
	getline(cin, presenter);

	cout << "Enter the new title: ";
	getline(cin, newTitle);
	cout << "Enter the new presenter: ";
	getline(cin, newPresenter);

	cout << "Enter the new duration:\n";
	cout << "Minutes: ";
	cin >> newDuration.minutes;
	cout << "Seconds: ";
	cin >> newDuration.seconds;

	cout << "Enter the new number of likes: ";
	cin >> newLikes;

	cout << "Enter the new link: ";
	cin.ignore();
	getline(cin, newLink);

	if (aservice.updateTutorial(title, presenter, newTitle, newPresenter, newDuration, newLikes, newLink))
	{
		cout << "Tutorial updated successfully." << endl;
	}
	else
	{
		cout << "Failed to update the tutorial. Either it doesn't exist or the new title/presenter already exist." << endl;
	}
}


void Ui::displayAllTutorials()
{
	vector<Tutorial> allTutorials = aservice.getAllTutorials();
	if (allTutorials.empty())
	{
		cout << "No tutorials available." << endl;
	}
	else
	{
		cout << "All Tutorials:" << endl;
		for (const auto& tutorial : allTutorials)
		{
			cout << "Title: " << tutorial.getTitle() << endl;
			cout << "Presenter: " << tutorial.getPresenter() << endl;
			cout << "Duration: " << tutorial.getDuration().minutes << " minutes, " << tutorial.getDuration().seconds << " seconds" << endl;
			cout << "Likes: " << tutorial.getLikes() << endl;
			cout << "Link: " << tutorial.getLink() << endl;
			cout << "----------------------" << endl;
		}
	}
}
//USER

void Ui::searchTutorialsByPresenter()
{
	string presenter;
	cout << "Enter the presenter name: ";
	cin.ignore();
	getline(cin, presenter);

	vector<Tutorial> allTutorials = aservice.getAllTutorials();
	vector<Tutorial> tutorialsOfPresenter = uservice.getTutorialsOfPresenter(allTutorials, presenter);

	if (tutorialsOfPresenter.empty())
	{
		cout << "No tutorials found for presenter: " << presenter << endl;
	}
	else
	{
		cout << "Tutorials by presenter " << presenter << ":" << endl;
		for (const auto& tutorial : tutorialsOfPresenter)
		{
			cout << "Title: " << tutorial.getTitle() << endl;
			cout << "Presenter: " << tutorial.getPresenter() << endl;
			cout << "Duration: " << tutorial.getDuration().minutes << " minutes, " << tutorial.getDuration().seconds << " seconds" << endl;
			cout << "Likes: " << tutorial.getLikes() << endl;
			cout << "Link: " << tutorial.getLink() << endl;
			cout << "----------------------" << endl;

			string userOption;
			cout << "Do you want to add this tutorial to your watchlist? (yes/no): ";
			cin >> userOption;

			if (userOption == "yes")
			{
				uservice.addTutorialToWatchlist(tutorial);
				cout << "Tutorial added to watchlist." << endl;
			}
		}
	}
}

void Ui::removeTutorialFromWatchlist()
{
	string title, presenter;
	cout << "Enter the title of the tutorial to remove from watchlist: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter the presenter of the tutorial to remove from watchlist: ";
	getline(cin, presenter);

	if (uservice.removeTutorialFromWatchlist(title, presenter))
	{
		cout << "Tutorial removed from watchlist." << endl;
	}
	else
	{
		cout << "Failed to remove tutorial from watchlist. Either it doesn't exist or the provided title/presenter is incorrect." << endl;
	}
}

void Ui::displayWatchlist()
{
	vector<Tutorial> watchlist = uservice.getWatchlist();
	if (watchlist.empty())
	{
		cout << "Watchlist is empty." << endl;
	}
	else
	{
		cout << "Watchlist:" << endl;
		for (const auto& tutorial : watchlist)
		{
			cout << "Title: " << tutorial.getTitle() << endl;
			cout << "Presenter: " << tutorial.getPresenter() << endl;
			cout << "Duration: " << tutorial.getDuration().minutes << " minutes, " << tutorial.getDuration().seconds << " seconds" << endl;
			cout << "Likes: " << tutorial.getLikes() << endl;
			cout << "Link: " << tutorial.getLink() << endl;
			cout << "----------------------" << endl;
		}
	}
}