#include "Painting.h"
#include <iomanip> 

// Static member variable initialization
std::set<Painting> Painting::paintings;

// Constructor
Painting::Painting(const string& name, const string& title, int yearProduced, const string& price)
    : Exhibition(name, "", "", "", "", "", ""), title(title), yearProduced(yearProduced), price(price) {}

// Getter and setter functions
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

// Overloaded function to set discounted price
void Painting::setPrice(double discountRate) {
    // Assuming price is a numerical value represented as a string
    // Calculate discounted price and update the price string
    double originalPrice = stod(price);
    double discountedPrice = originalPrice * (1 - discountRate);
    price = to_string(discountedPrice);
}

// Static function to display painting details
void Painting::displayPaintingDetails(const Painting& painting) {
    cout << "Name: " << painting.getExhibitionName() << endl;
    cout << "Title: " << painting.getTitle() << endl;
    cout << "Year Produced: " << painting.getYearProduced() << endl;
    cout << "Price: " << painting.getPrice() << endl;
}

// Set exhibition name function/ function with default argument 
/*You can add a function with default parameter in this code.
We wouldn't hope to add the setExhibitionName function 
that allows us to enjoy the default gallery name "Unknown Exhibition"
if its efficiency is not gained.*/
void Painting::setExhibitionName(const string& newName) {
    exhibitionName = newName;
}