#include "Movie.h"
#include <ctime> 
#include <sstream>
#include <stdexcept>
// Constructor
Movie::Movie(const std::string& title, const std::string& genre, const std::string& trailer, int yearOfRelease, int likesCount) : title{ title }, genre{ genre }, trailer{ trailer }, yearOfRelease{ yearOfRelease }, likesCount{ likesCount } {};

// Destructor
Movie::~Movie() {}

Movie::Movie(const Movie& movie)
{
    this->title = movie.title;
    this->genre = movie.genre;
    this->trailer = movie.trailer;
    this->yearOfRelease = movie.yearOfRelease;
    this->likesCount = movie.likesCount;
}

// Assignment operator
Movie& Movie::operator=(const Movie& movie)
{
    if (this == &movie)
        return *this;

    this->title = movie.title;
    this->genre = movie.genre;
    this->trailer = movie.trailer;
    this->yearOfRelease = movie.yearOfRelease;
    this->likesCount = movie.likesCount;

    return *this;
}

bool Movie::operator==(const Movie& movie) const
{
    return this->title == movie.title && this->genre == movie.genre && this->yearOfRelease == movie.yearOfRelease;
}

// Getters
std::string Movie::getTitle() const
{
    return this->title;
}

std::string Movie::getGenre() const
{
    return this->genre;
}

std::string Movie::getTrailer() const
{
    return this->trailer;
}


void Movie::validateYearOfRelease(int yearOfRelease)
{
    std::time_t result;
    if (std::time(&result) == -1) {
        throw std::runtime_error("Failed to get current time");
    }

    char buffer[26];
    if (ctime_s(buffer, sizeof(buffer), &result) != 0) {
        throw std::runtime_error("Failed to convert time to string");
    }

    std::istringstream iss(buffer);
    iss.ignore(20);
    int currentYear;
    iss >> currentYear;

    if (yearOfRelease < 0 || yearOfRelease > currentYear)
        throw std::invalid_argument("Year of release must be a positive integer");
}

void Movie::validateLikesCount(int likesCount)
{
    if (likesCount < 0)
        throw std::invalid_argument("Likes count must be a positive integer");
}

void Movie::validateMovie()
{
    validateYearOfRelease(this->yearOfRelease);
    validateLikesCount(this->likesCount);
}

// Setters
int Movie::getYearOfRelease() const
{
    return this->yearOfRelease;
}

int Movie::getLikesCount() const
{
    return this->likesCount;
}

void Movie::setTitle(const std::string& title)
{
    this->title = title;
}

void Movie::setGenre(const std::string& genre)
{
    this->genre = genre;
}

void Movie::setTrailer(const std::string& trailer)
{
    this->trailer = trailer;
}

void Movie::setYearOfRelease(int yearOfRelease)
{
    // Defensive programming
    this->validateYearOfRelease(yearOfRelease);
    this->yearOfRelease = yearOfRelease;
}

void Movie::setLikesCount(int likesCount)
{
    // Defensive programming
    this->validateLikesCount(likesCount);
    this->likesCount = likesCount;
}