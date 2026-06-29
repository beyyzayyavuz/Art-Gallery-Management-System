#include "Exhibition.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor: builds the featured Artist via composition.
Exhibition::Exhibition(const string& name, const string& startDate, const string& endDate,
    const string& location, const string& artistName,
    const string& artistDateOfBirth, const string& artistNationality)
    : name(name), startDate(startDate), endDate(endDate), location(location),
    artist(artistName, artistDateOfBirth, artistNationality) {}

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

const Artist& Exhibition::getArtist() const {
    return artist;
}

void Exhibition::displayDetails() const {
    artist.displayDetails(); // Delegate to the composed Artist
    cout << "Exhibition Name: " << name << endl;
    cout << "Start Date: " << startDate << ", End Date: " << endDate << endl;
    cout << "Location: " << location << endl;
    cout << "Paintings in the Exhibition:" << endl;
    for (const string& painting : paintings) {
        cout << painting << endl;
    }
}

void Exhibition::addPainting(const string& paintingTitle) {
    // Check if the painting already exists in the exhibition
    auto it = find(paintings.begin(), paintings.end(), paintingTitle);
    if (it != paintings.end()) {
        cout << "Painting \"" << paintingTitle << "\" already exists in the exhibition." << endl;
    }
    else {
        paintings.push_back(paintingTitle);
    }
}

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
