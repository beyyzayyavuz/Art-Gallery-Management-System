#include "Exhibition.h"
#include <iostream>
#include <algorithm>
// Constructor
Exhibition::Exhibition(const string& name, const string& startDate, const string& endDate, const string& location, const string& artistName, const string& artistDateOfBirth, const string& artistNationality)
    : Artist(artistName, artistDateOfBirth, artistNationality), name(name), startDate(startDate), endDate(endDate), location(location) {}

// Getter and setter functions
string Exhibition::getExhibitionName() const {
    return name;
}

void Exhibition::setExhibitionName(const string& newName) {
    name = newName;
}

string Exhibition::getStartDate() const {
    return startDate;
}

void Exhibition::setStartDate(const string& newStartDate) {
    startDate = newStartDate;
}

string Exhibition::getEndDate() const {
    return endDate;
}

void Exhibition::setEndDate(const string& newEndDate) {
    endDate = newEndDate;
}

string Exhibition::getLocation() const {
    return location;
}

void Exhibition::setLocation(const string& newLocation) {
    location = newLocation;
}

// Declaring displayDetails function
void Exhibition::displayDetails() const {
    Artist::displayDetails();
    cout << "Exhibition Name: " << name << endl;
    cout << "Start Date: " << startDate << ", End Date: " << endDate << endl;
    cout << "Location: " << location << endl;
    cout << "Paintings in the Exhibition:" << endl;
    for (const string& painting : paintings) {
        cout << painting << endl;
    }
}

// Inside the addPainting function
void Exhibition::addPainting(const string& paintingTitle) {
    // Check if the painting already exists in the exhibition
    // It is used to search for an element with the value paintingTitle in the range defined by the iterators paintings.begin() and paintings.end().
    auto it = find(paintings.begin(), paintings.end(), paintingTitle);
    if (it != paintings.end()) {
        cout << "Painting \"" << paintingTitle << "\" already exists in the exhibition." << endl;
    }
    else {
        paintings.push_back(paintingTitle);
    }
}

// Inside the removePainting function
bool Exhibition::removePainting(const string& paintingTitle) {
    auto it = find(paintings.begin(), paintings.end(), paintingTitle);
    if (it != paintings.end()) {
        paintings.erase(it);
        cout << "Painting \"" << paintingTitle << "\" removed successfully." << endl;
        return true; // Painting found and removed
    }
    else {
        cout << "Painting \"" << paintingTitle << "\" not found." << endl;
        return false; // Painting not found
    }
}
