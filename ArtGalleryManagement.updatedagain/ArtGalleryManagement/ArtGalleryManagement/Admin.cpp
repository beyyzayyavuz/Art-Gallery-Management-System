#include "Admin.h"

Admin::Admin(const string& _username)
    : user(_username) {}

// Defining the overriding function
void Admin::displayMenu() const {
    cout << "Welcome, " << username << "!" << endl;
    cout << "1. Add new painting" << endl;
    cout << "2. Remove painting" << endl;
    cout << "3. Exit" << endl;
}
