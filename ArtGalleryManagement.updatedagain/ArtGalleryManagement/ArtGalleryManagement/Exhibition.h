#ifndef EXHIBITION_H
#define EXHIBITION_H

#include "Artist.h" // Assuming Artist class is defined in Artist.h
#include <vector>
#include <string>
#include <map> 
#include <set>
#include <algorithm>
using namespace std;

class Exhibition : public Artist {
private:
    string name;
    string startDate;
    string endDate;
    string location;
    vector<string> paintings; // Assuming just titles of paintings for simplicity

public:
    // Constructor
    Exhibition(const string& name, const string& startDate, const string& endDate, const string& location, const string& artistName, const string& artistDateOfBirth, const string& artistNationality);

    // Getter and setter functions
    string getExhibitionName() const;
    void setExhibitionName(const string& newName);
    string getStartDate() const;
    void setStartDate(const string& newStartDate);
    string getEndDate() const;
    void setEndDate(const string& newEndDate);
    string getLocation() const;
    void setLocation(const string& newLocation);

    // It is a data structure used to store information about paintings organized by exhibition.
    map<string, std::set<string>> paintingsByExhibition;

    // Declaring an overriding function: displayDetails()
    void displayDetails() const;

    void addPainting(const string& paintingTitle);
    bool removePainting(const string& paintingTitle);

    const vector<string>& getPaintings() const {
        return paintings;
    }


    // Public method to clear the paintings collection
    void clearPaintings() {
        paintings.clear();
    }
};

#endif /* EXHIBITION_H */
