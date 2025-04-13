#ifndef VISITOR_H
#define VISITOR_H

#include "user.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Exhibition.h"



using namespace std;

class Visitor1 : public user {
public:
    Visitor1();

    void displayMenu() const override;

    void searchPaintings(const string& searchQuery, const string& filename);

    void viewExhibitionMenu(const vector<Exhibition>& exhibitions) const;

    void viewExhibitionDetails(const Exhibition& exhibition) const;

    void viewPaintingDetails(const Exhibition& exhibition, const string& paintingName) const;

    void viewPaintingDetails(const Exhibition& exhibition) const;
};

#endif /* VISITOR_H */