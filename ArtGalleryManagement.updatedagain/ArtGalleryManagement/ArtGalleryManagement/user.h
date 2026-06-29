#ifndef USER_H
#define USER_H

#include <string>

class user {
protected:
    std::string username;

public:
    user(const std::string& username);
    virtual ~user() = default; // Virtual destructor so deleting via base pointer is safe

    // displayMenu() is a pure virtual (overriding) function.
    // Using the virtual keyword for runtime polymorphism.
    virtual void displayMenu() const = 0;
};

#endif /* USER_H */
