#ifndef EXHIBITION_H
#define EXHIBITION_H

#include "Artist.h"
#include <vector>
#include <string>

// An Exhibition HAS a featured Artist (composition) rather than being one.
class Exhibition {
private:
    std::string name;
    std::string startDate;
    std::string endDate;
    std::string location;
    Artist artist;                     // Featured artist (composition)
    std::vector<std::string> paintings; // Titles of paintings for simplicity

public:
    Exhibition(const std::string& name, const std::string& startDate, const std::string& endDate,
        const std::string& location, const std::string& artistName,
        const std::string& artistDateOfBirth, const std::string& artistNationality);

    // Getter and setter functions
    std::string getExhibitionName() const;
    void setExhibitionName(const std::string& newName);
    std::string getStartDate() const;
    void setStartDate(const std::string& newStartDate);
    std::string getEndDate() const;
    void setEndDate(const std::string& newEndDate);
    std::string getLocation() const;
    void setLocation(const std::string& newLocation);
    const Artist& getArtist() const;

    void displayDetails() const;

    void addPainting(const std::string& paintingTitle);
    bool removePainting(const std::string& paintingTitle);

    const std::vector<std::string>& getPaintings() const {
        return paintings;
    }

    // Public method to clear the paintings collection
    void clearPaintings() {
        paintings.clear();
    }
};

#endif /* EXHIBITION_H */
