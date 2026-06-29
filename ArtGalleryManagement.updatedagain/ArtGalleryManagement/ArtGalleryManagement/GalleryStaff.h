#ifndef GALLERYSTAFF_H
#define GALLERYSTAFF_H

#include "user.h"
#include <set>
#include <string>

class GalleryStaff : public user {
public:
    GalleryStaff(const std::string& username);

    // Overriding function
    void displayMenu() const override;

    // manageInventory with a default argument
    void manageInventory(const std::set<std::string>& inventoryList = {});

    void personnels(const std::set<std::string>& personnelNames);
};

#endif /* GALLERYSTAFF_H */
