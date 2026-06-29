#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <string>

class Admin : public user {
public:
    Admin(const std::string& _username);

    // Overriding function
    void displayMenu() const override;
};

#endif /* ADMIN_H */
