#ifndef VISITOR_H
#define VISITOR_H

#include "user.h"
#include "Exhibition.h"
#include <string>
#include <vector>

class Visitor1 : public user {
public:
    Visitor1();

    void displayMenu() const override;

    void searchPaintings(const std::string& searchQuery, const std::string& filename);

    void viewExhibitionMenu(const std::vector<Exhibition>& exhibitions) const;

    void viewExhibitionDetails(const Exhibition& exhibition) const;

    void viewPaintingDetails(const Exhibition& exhibition, const std::string& paintingName) const;
};

#endif /* VISITOR_H */
