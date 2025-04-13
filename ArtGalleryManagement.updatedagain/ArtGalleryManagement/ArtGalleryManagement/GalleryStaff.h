#ifndef GALLERYSTAFF_H
#define GALLERYSTAFF_H

#include "user.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;

class GalleryStaff : public user {
public:
    GalleryStaff(const string& username);
    //Declaring overriding function
    void displayMenu() const override;

    // Modified manageInventory function with default argument
    void manageInventory(const set<string>& inventoryList = {});

    void personnels(const set<string>& personnelNames);
};

#endif /* GALLERYSTAFF_H */
