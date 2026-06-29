#ifndef PAINTING_H
#define PAINTING_H

#include <string>

// A Painting is a standalone entity. It is associated with an exhibition by
// name, but it is NOT a kind of Exhibition (composition/association, not inheritance).
class Painting {
private:
    std::string exhibitionName;
    std::string title;
    int yearProduced;
    std::string price;

public:
    Painting(const std::string& exhibitionName, const std::string& title, int yearProduced, const std::string& price);

    std::string getExhibitionName() const;
    void setExhibitionName(const std::string& newName = "Unknown Exhibition"); // Default argument
    std::string getTitle() const;
    void setTitle(const std::string& newTitle);
    int getYearProduced() const;
    void setYearProduced(int newYearProduced);
    std::string getPrice() const;
    void setPrice(const std::string& newPrice); // Overloaded setter
    void setPrice(double discountRate);          // Overloaded setter

    // Static helper to display painting details
    static void displayPaintingDetails(const Painting& painting);
};

#endif /* PAINTING_H */
