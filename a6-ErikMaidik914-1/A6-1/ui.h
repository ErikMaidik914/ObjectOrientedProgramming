#pragma once
#include<string>
#include"Aservice.h"
#include"Uservice.h"

using namespace std;

class Ui
{
private:
	Aservice aservice;
	Uservice uservice;

public:
	Ui(Aservice initialAdminService, Uservice initialUserService) : aservice{ initialAdminService }, uservice{initialUserService} {}
	//administrator functionalities
	void addTutorial();
	void removeTutorial();
	void updateTutorial();
	void displayAllTutorials();
	void printAdministratorMenu();
	void administratorMode();

	//user functionalities
	void searchTutorialsByPresenter();
	void removeTutorialFromWatchlist();
	void displayWatchlist();
	void printUserMenu();
	void userMode();

	void run();
};