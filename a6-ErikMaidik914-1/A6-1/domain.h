#pragma once
#include<string>

using namespace std;

typedef struct
{
	int minutes, seconds;
}Duration;

class Tutorial
{
private:
	string title;
	string presenter;
	int likes;
	Duration duration;
	string link;
public:
	Tutorial() : title(""), presenter(""), likes(0), duration({ 0, 0 }), link("") {}
	Tutorial(string title, string presenter, Duration duration, int likes, string link);
	string getTitle() const;
	string getPresenter() const; 
	Duration getDuration() const;
	int getLikes() const;
	string getLink() const;
	void setTitle(string newTitle);
	void setPresenter(string newPresenter);
	void setDuration(Duration newDuration);
	void setLikes(int newLikes);
	void setLink(string newLink);
};