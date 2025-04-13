#include "Visitor1.h"
#include "Exhibition.h"
#include "Painting.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Visitor1::Visitor1()
    : user("Visitor") {}

void Visitor1::displayMenu() const {
    cout << "Welcome, " << username << "!" << endl;
    cout << "1. View current exhibitions" << endl;
    cout << "2. Search for paintings" << endl;
    cout << "3. View currently available paintings" << endl;
    cout << "4. View newly added paintings" << endl;
    cout << "5. View the artists with exhibitions in this gallery" << endl;
    cout << "6. Exit" << endl;
}

void Visitor1::searchPaintings(const string& searchQuery, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string painting;
        bool found = false;
        while (getline(file, painting)) {
            // Check if the current painting contains the search query
            if (painting.find(searchQuery) != string::npos) {
                // Display the painting if found
                cout << painting << endl;
                cout << "This painting just arrived at the gallery. It will be presented in the exhibition soon!" << endl;
                found = true;
            }
        }
        file.close();

        // If no matching paintingss were found
        if (!found) {
            cout << "No paintings matching the search query found." << endl;
        }
    }
    else {
        cout << "Unable to open file for searching paintings." << endl;
    }
}

// Function to display the menu of available exhibitions for viewing
void Visitor1::viewExhibitionMenu(const vector<Exhibition>& exhibitions) const {
    cout << "Select an exhibition to view details:" << endl;
    for (int i = 0; i < exhibitions.size(); ++i) {
        cout << i + 1 << ". " << exhibitions[i].getExhibitionName() << endl;
    }
    cout << exhibitions.size() + 1 << ". Return to main menu" << endl;
}

// Function to display details of a specific exhibition
void Visitor1::viewExhibitionDetails(const Exhibition& exhibition) const {
    cout << "Exhibition Name: " << exhibition.getExhibitionName() << endl;
    cout << "Start Date: " << exhibition.getStartDate() << ", End Date: " << exhibition.getEndDate() << endl;
    cout << "Location: " << exhibition.getLocation() << endl;
}

// Function to display details of a specific painting in an exhibition
void Visitor1::viewPaintingDetails(const Exhibition& exhibition, const string& paintingName) const {
    // Get the paintings from the exhibition
    const vector<string>& paintings = exhibition.getPaintings();

    auto it = find_if(paintings.begin(), paintings.end(), [&](const string& paintingTitle) {
        return paintingTitle == paintingName;
        });

    if (it != paintings.end()) {
        cout << "Details of Painting \"" << paintingName << "\":" << endl;
    }
    // If the painting is not found, display a message
    else {
        cout << "Painting not found in the exhibition." << endl;
    }
}
