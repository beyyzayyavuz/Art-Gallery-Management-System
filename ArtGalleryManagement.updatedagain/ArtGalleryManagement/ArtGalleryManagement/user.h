#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class user {
protected:
    string username;

public:
    user(const string& username);
    // displayMenu() is an overriding function. 
    // Using the virtual keyword for runtime polymorphism.
    virtual void displayMenu() const = 0;
};

#endif /* USER_H */
