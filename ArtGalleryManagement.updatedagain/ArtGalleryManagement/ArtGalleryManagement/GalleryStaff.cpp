#include "GalleryStaff.h"

GalleryStaff::GalleryStaff(const string& username)
    : user(username) {}

void GalleryStaff::displayMenu() const {
    cout << "Welcome, " << username << "!" << endl;
    cout << "1. List of inventory" << endl;
    cout << "2. View personnels" << endl;
    cout << "3. Exit" << endl;
}

// Modified manageInventory function with default argument
void GalleryStaff::manageInventory(const set<string>& inventoryList) {
    cout << "Inventory List:" << endl;
    if (inventoryList.empty()) {
        cout << "No inventory available." << endl;
    }
    else {
        for (const string& name : inventoryList) {
            cout << "* " << name << endl;
        }
    }
}


void GalleryStaff::personnels(const set<string>& personnelNames) {
    cout << "Personnel names:" << endl;
    for (const string& name : personnelNames) {
        cout << "- " << name << endl;
    }
}
