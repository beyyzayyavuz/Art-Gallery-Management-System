#ifndef ARTIST_H
#define ARTIST_H

#include <string>

class Artist {
private:
    std::string name;
    std::string dateOfBirth;
    std::string nationality;

public:
    Artist(const std::string& name, const std::string& dateOfBirth, const std::string& nationality);

    std::string getName() const;
    void setName(const std::string& newName);
    std::string getDateOfBirth() const;
    void setDateOfBirth(const std::string& newDateOfBirth);
    std::string getNationality() const;
    void setNationality(const std::string& newNationality);
    // Declaring an overriding function: displayDetails()
    virtual void displayDetails() const;
    // Declaring a friend function: displayMessage(const Artist& artist, const std::string& quota)
    friend void displayMessage(const Artist& artist, const std::string& quota);
};

#endif // ARTIST_H
