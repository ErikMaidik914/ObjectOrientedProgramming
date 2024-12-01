#include<string>
#include"domain.h"

using namespace std;

Tutorial::Tutorial(string title, string presenter, Duration duration, int likes, string link)
{
    this->title = title;
    this->presenter = presenter;
    this->duration = duration;
    this->likes = likes;
    this->link = link;

}

string Tutorial::getTitle() const
{
    return this->title;
}

string Tutorial::getPresenter() const
{
    return this->presenter;
}

Duration Tutorial::getDuration() const
{
    return this->duration;
}

int Tutorial::getLikes() const
{
    return this->likes;
}

string Tutorial::getLink() const
{
    return this->link;
}

void Tutorial::setTitle(string newTitle)
{
    this->title = newTitle;
}

void Tutorial::setPresenter(string newPresenter)
{
    this->presenter = newPresenter;
}

void Tutorial::setDuration(Duration newDuration)
{
    this->duration = newDuration;
}

void Tutorial::setLikes(int newLikes)
{
    this->likes = newLikes;
}

void Tutorial::setLink(string newLink)
{
    this->link = newLink;
}