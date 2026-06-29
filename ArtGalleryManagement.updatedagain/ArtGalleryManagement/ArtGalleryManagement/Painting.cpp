#include "Painting.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
Painting::Painting(const string& exhibitionName, const string& title, int yearProduced, const string& price)
    : exhibitionName(exhibitionName), title(title), yearProduced(yearProduced), price(price) {}

// Getter and setter functions
string Painting::getExhibitionName() const {
    return exhibitionName;
}

void Painting::setExhibitionName(const string& newName) {
    exhibitionName = newName;
}

string Painting::getTitle() const {
    return title;
}

void Painting::setTitle(const string& newTitle) {
    title = newTitle;
}

int Painting::getYearProduced() const {
    return yearProduced;
}

void Painting::setYearProduced(int newYearProduced) {
    yearProduced = newYearProduced;
}

string Painting::getPrice() const {
    return price;
}

void Painting::setPrice(const string& newPrice) {
    price = newPrice;
}

// Overloaded function to apply a discount to the price.
void Painting::setPrice(double discountRate) {
    try {
        double originalPrice = stod(price);
        double discountedPrice = originalPrice * (1 - discountRate);
        price = to_string(discountedPrice);
    }
    catch (const std::exception&) {
        // Price was not a numeric string; leave it unchanged.
        cout << "Warning: price \"" << price << "\" is not numeric; discount not applied." << endl;
    }
}

// Static function to display painting details
void Painting::displayPaintingDetails(const Painting& painting) {
    cout << "Name: " << painting.getExhibitionName() << endl;
    cout << "Title: " << painting.getTitle() << endl;
    cout << "Year Produced: " << painting.getYearProduced() << endl;
    cout << "Price: " << painting.getPrice() << endl;
}
