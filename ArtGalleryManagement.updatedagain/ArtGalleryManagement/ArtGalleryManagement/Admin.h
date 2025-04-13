#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <iostream>
using namespace std;

class Admin : public user {
public:
    Admin(const string& _username);
    
    // Declaring an overriding function
    void displayMenu() const override;
};

#endif /* ADMIN_H */
