#ifndef PAINTING_H
#define PAINTING_H

#include "Exhibition.h"
#include <string>
#include <iostream>
#include <set>

using namespace std;

class Painting : public Exhibition {
private:
    string title;
    int yearProduced;
    string price;
    // Declaring a static variable: 
    static std::set<Painting> paintings;
    string exhibitionName; 

public:
    Painting(const string& name, const string& title, int yearProduced, const string& price);
    string getTitle() const;
    void setTitle(const string& newTitle);
    int getYearProduced() const;
    void setYearProduced(int newYearProduced);
    string getPrice() const;
    void setPrice(const string& newPrice); //Declaring an overloading function
    void setPrice(double discountRate);
    // Declaring an static function: displayPaintingDetails(const Painting& painting)
    static void displayPaintingDetails(const Painting& painting);
    // Function with default argument 
    void setExhibitionName(const string& newName = "Unknown Exhibition"); 
};

#endif /* PAINTING_H */