#include "artist.h"
#include <iostream>

Artist::Artist(const std::string& name, const std::string& dateOfBirth, const std::string& nationality)
    : name(name), dateOfBirth(dateOfBirth), nationality(nationality) {}

std::string Artist::getName() const {
    return name;
}

void Artist::setName(const std::string& newName) {
    name = newName;
}

std::string Artist::getDateOfBirth() const {
    return dateOfBirth;
}

void Artist::setDateOfBirth(const std::string& newDateOfBirth) {
    dateOfBirth = newDateOfBirth;
}

std::string Artist::getNationality() const {
    return nationality;
}

void Artist::setNationality(const std::string& newNationality) {
    nationality = newNationality;
}

// Definition of the overriding function: displayDetails()
void Artist::displayDetails() const {
    std::cout << "Artist Name: " << name << std::endl;
    std::cout << "Date of Birth: " << dateOfBirth << std::endl;
    std::cout << "Nationality: " << nationality << std::endl;
}

// Definiton of the friend function: displayMessage(const Artist& artist, const std::string& quota)
void displayMessage(const Artist& artist, const std::string& quota) {
    std::cout << "Artist: " << artist.getName() << std::endl;
    std::cout << "Quota: " << quota << std::endl;
}
