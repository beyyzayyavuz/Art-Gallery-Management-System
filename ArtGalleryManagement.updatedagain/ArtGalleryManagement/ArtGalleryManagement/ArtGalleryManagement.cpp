#include <iostream>
#include <fstream>  // For file handling
#include <string>
#include <algorithm> // Provides various algorithms that operate collection of elements. (There was a need for the find() and search() functions to be called in main())
#include <set> // Provides the definition of the std::set container, which is a sorted associative container.
#include "artist.h"
#include "user.h"
#include "painting.h"
#include "Visitor1.h"
#include "Admin.h"
#include "GalleryStaff.h"
using namespace std;
// Function to perform login
user* login() {
    std::cout << "Welcome to Art Gallery Management System!" << endl;
    std::cout << "=========================================" << endl;
    std::cout << "Log in:" << endl;
    std::cout << "1) Visitor" << endl;
    std::cout << "2) Gallery Staff" << endl;
    std::cout << "3) Admin" << endl;

    int choice;
    cin >> choice;
    //THE PASSWORDS OF ADMIN AND GALLERY STAFF ARE BELOW:
    //The admin's password is: 1234
    //The gallery staff's password is: 4321.
    if (choice == 1) {
        return new Visitor1();
    }
    else if (choice == 2) {
        string password;
        std::cout << "Enter password: ";
        cin >> password;
        if (password == "4321") {
            return new GalleryStaff("Staff");
        }
        else {
            std::cout << "Incorrect password. Access denied." << endl;
            return nullptr;
        }
    }
    else if (choice == 3) {
        string password;
        std::cout << "Enter password: ";
        cin >> password;
        if (password == "1234") {
            return new Admin("Admin");
        }
        else {
            std::cout << "Incorrect password. Access denied." << endl;
            return nullptr;
        }
    }
    else {
        std::cout << "Invalid choice. Please try again." << endl;
        return nullptr;
    }
}

// This function takes an Exhibition object and a filename as input parameters. It attempts to open a file with the given filename for writing.
void savePaintingsToFile(const Exhibition& exhibition, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const std::string& painting : exhibition.getPaintings()) {
            file << painting << std::endl;
        }
        file.close();
        std::cout << "Paintings saved to file successfully!" << std::endl;
    }
    else {
        std::cout << "Unable to open file for saving paintings." << std::endl;
    }
}
// This function loads paintings from a file into the specified exhibition.
void loadPaintingsFromFile(Exhibition& exhibition, const std::string& filename) {
    std::ifstream file(filename);
    // Checks if the file stream associated with the ifstream object. It returns true if the file is open and ready to be read from or written to; false if the file failed to open or if it was already closed.
    if (file.is_open()) {
        std::string painting;
        // It reads each line from the file, representing a painting, and adds it to the exhibition.
        while (getline(file, painting)) {
            exhibition.addPainting(painting);
        }
        //Once all the paintings have been read from the file and added to the exhibition, we need to close the file stream.
        file.close(); 
        // If the painting is successfully added, it prints a success message.
        std::cout << "Paintings loaded from file successfully!" << std::endl;
    }
    else {
        // If the file cannot be opened, it prints an error message.
        std::cout << "Unable to open file for loading paintings." << std::endl;
    }
}
// Declare a set named 'paintings' to store instances of the 'Painting' class.
std::set<Painting> paintings;
int main() {
    // This creates an Exhibition object named 'exhibition'. 
    // It's specified that only paintings added by the admin user are included in this exhibition, assuming other exhibitions are already full. 
    Exhibition exhibition("Vibrant Perspectives", "May 15, 2024", "August 31, 2024", "Art Garden", "Paul Cezanne", "January 19, 1839", "Dutch");

    // This code snippet initializes an array named 'exhibitions' of type Exhibition using the constructor of the Exhibition class.
    Exhibition exhibitions[] = {
    Exhibition("Renaissance Rediscovered", "May 5, 2024", "June 28, 2024", "Art Museum", "Leonardo da Vinci", "April 15, 1452", "Italian"),
    Exhibition("Impressionist Masterpieces", "January 1, 2024", "December 31, 2024", "Art Gallery", "Vincent van Gogh", "March 30, 1853", "Dutch"),
    Exhibition("Abstract Expressionism", "April 5, 2024", "May 30, 2024", "Modern Art Center", "Pablo Picasso", "October 25, 1881", "Spanish")
    };

    // This code snippet initializes an array named 'paintings' of type Painting using the constructor of the Painting class.
    Painting paintings[] = {
    Painting("Renaissance Rediscovered", "Mona Lisa", 1503, "1000000"),
    Painting("Impressionist Masterpieces", "The Starry Night", 1889, "5000000"),
    Painting("Abstract Expressionism", "Guernica", 1937, "20000000")
};
    // This code snippet initializes an array named 'artists' of type Artist using the constructor of the Artist class. The data
    Artist artists[] = {
        Artist("Leonardo da Vinci", "April 15, 1452", "Italian"),
        Artist("Vincent van Gogh", "March 30, 1853", "Dutch"),
        Artist("Pablo Picasso", "October 25, 1881", "Spanish")
    };




    // Declares a pointer variable named 'currentUser' of type 'user*', initialized to nullptr.
    // This pointer is intended to store the currently logged-in user in the system.
    user* currentUser = nullptr;

    // Perform login
    while (!currentUser) {
        currentUser = login();
    }

    // Display menu based on user type
    currentUser->displayMenu();
    // If the logged-in user is an admin, dynamic_cast the currentUser pointer to an Admin pointer and assign it to the variable 'admin'.
    // dynami_cast: It allows you to convert pointers or references of base classes to pointers or references of derived classes, and vice versa.
    if (Admin* admin = dynamic_cast<Admin*>(currentUser)) {
        int choice;
        do {
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == 1) {
                std::string paintingTitle;
                std::cout << "************************ " << endl;
                std::cout << "Enter the title of the painting to add to the gallery: ";
                // Clears any leftover newline character in the input buffer to prevent it from affecting the subsequent getline operation.
                std::cin.ignore(); 
                // getline(cin, paintingTitle) reads a line of input from the standard input (cin) stream and stores it in the variable 'paintingTitle'.
                std::getline(std::cin, paintingTitle);
                // Check if the painting already exists before adding it
                if (std::find(exhibition.getPaintings().begin(), exhibition.getPaintings().end(), paintingTitle) == exhibition.getPaintings().end()) {
                    // Add the painting to the exhibition                  
                    exhibition.addPainting(paintingTitle); // Note: The added paintings are directed to "exhibition," not the set "exhibitions."                    
                    savePaintingsToFile(exhibition, "paintings.txt"); // Save paintings to file after adding the new painting                   
                    exhibition.displayDetails(); // Calling the overriding function: displayDetails to show the details of exhibiton
                    std::cout << "Painting added successfully!" << std::endl;
                    std::cout << "************************ " << endl;
                }
                else {
                    std::cout << "Painting already exists." << std::endl;
                }
            }
            else if (choice == 2) {
                // Remove paintings
                std::cout << "************************ " << endl;
                std::string paintingToRemove;
                std::cout << "Enter the title of the painting to remove: ";
                std::cin.ignore(); // Ignore newline character left in the buffer
                std::getline(std::cin, paintingToRemove);
                // If the removePainting() function returns true, it indicates that the specified painting was successfully removed from the exhibition.
                if (exhibition.removePainting(paintingToRemove)) {
                    // Save paintings to file after removing the painting
                    savePaintingsToFile(exhibition, "paintings.txt");
                    exhibition.displayDetails();
                    std::cout << "Painting removed successfully!" << std::endl;
                }
                else {
                    std::cout << "Painting not found." << std::endl;
                    std::cout << "************************ " << endl;
                }
            }
            else if (choice == 3) {
                // Exit when the user chooses option 3
                break;
            }
            else {
                std::cout << "Invalid choice." << std::endl;
            }

            // Display the admin menu again after each operation
            admin->displayMenu();
        } while (true); // The loop will terminate when the admin presses the number 3.
    }

    if (Visitor1* visitor1 = dynamic_cast<Visitor1*>(currentUser)) {
    int choice;
    bool viewingExhibition = false;

    do {
        std::cout << "Enter your choice: ";
        cin >> choice;
        std::cout << " "<<endl;
        // If the user chooses to view exhibitions
        if (choice == 1) {
            // Display the exhibition menu
            visitor1->viewExhibitionMenu(vector<Exhibition>(begin(exhibitions), end(exhibitions)));
            std::cout << "Enter your choice: ";
            cin >> choice;
            // If the user chooses an exhibition:
            if (choice >= 1 && choice <= sizeof(exhibitions) / sizeof(exhibitions[0])) {
                std::cout << "************************ " << endl;
                // Clear any previous paintings in the exhibition
                exhibitions[choice - 1].clearPaintings();

                // Add paintings to the selected exhibition
                for (const Painting& painting : paintings) {
                    exhibitions[choice - 1].addPainting(paintings[choice - 1].getTitle());
                }

                // Display details of the selected exhibition
                visitor1->viewExhibitionDetails(exhibitions[choice - 1]);

                viewingExhibition = true;
                std::cout << "************************ " << endl;
            }
            // If the user chooses to return to the main menu
            else if (choice == sizeof(exhibitions) / sizeof(exhibitions[0]) + 1) {
                // Return to main menu
                viewingExhibition = false;
            }
            else {
                std::cout << "Invalid choice. Please try again." << endl; 
            }
        }
        // If the user chooses to search paintings
        else if (choice == 2) {
            string searchQuery;
            std::cout << "************************ " << endl;
            std::cout << "Enter the search query: ";
            cin.ignore(); // Ignore newline character left in the buffer
            getline(cin, searchQuery);
            visitor1->searchPaintings(searchQuery, "paintings.txt"); // Perform the search and display the results
            std::cout << "************************ " << endl;
        }
        else if (choice == 3) {
            // View available paintings
            std::cout << "************************ " << endl;
            std::cout << "Available paintings:" << endl;
            for (const Painting& painting : paintings) {
                // Calling static function displayPaintingDetails(const Painting& painting) by class name "Painting"
                // Overloading function is used: setPrice(const string& newPrice)
                Painting::displayPaintingDetails(painting);
            }
            std::cout << "------------------------" << endl;
            std::cout << " " << endl;
            // Overloading function is used: setPrice(double discountRate)
            // Display detailed painting prices with applied discounts
            std::cout << "DETAILED PAINTING PRICES" << endl;
            std::cout << "The original price of " << paintings[0].getTitle() << ": " << paintings[0].getPrice() << endl;
            // Applying a discount rate of 10%
            paintings[0].setPrice(0.1);
            // Displaying discounted price
            std::cout << "The discounted price of " << paintings[0].getTitle() << ": " << paintings[0].getPrice() << endl;
            std::cout << "----------------------" << endl;
            std::cout << "The original price of " << paintings[1].getTitle() << ": " << paintings[1].getPrice() << endl;
            // Applying a discount rate of 2%
            paintings[1].setPrice(0.02);
            // Displaying discounted price
            std::cout << "The discounted price of " << paintings[1].getTitle() << ": " << paintings[1].getPrice() << endl;
            std::cout << "----------------------" << endl;
            std::cout << "The original price of " << paintings[2].getTitle() << ": " << paintings[2].getPrice() << endl;
            // Applying a discount rate of 30%
            paintings[2].setPrice(0.3);
            // Displaying discounted price
            std::cout << "The discounted price of " << paintings[2].getTitle() << ": " << paintings[2].getPrice() << endl;
            std::cout << "************************ " << endl;
        }
        // If the user chooses to view the contents of the paintings.txt file and is not currently viewing an exhibition:
        else if (choice == 4) {
            // View contents of paintings.txt file
            std::cout << "************************ " << endl;
            std::cout << "Newly added paintings:" << endl;
            // Open the paintings.txt file
            ifstream file("paintings.txt");
            if (file.is_open()) {
                string painting;
                while (getline(file, painting)) {
                    std::cout << painting << endl;
                }
                file.close();
                std::cout << "************************ " << endl;
            }
            else {
                std::cout << "Unable to open paintings.txt file." << endl;
            }
        }
        // If the user chooses to view artist details
        else if (choice == 5) {
            std::cout << "************************ " << endl;
            artists[0].displayDetails();
            // Calling the friend function: displayMessage(const Artist& artist, const std::string& quota)
            displayMessage(artists[0], "Love shines brightest in the darkest places.");
            artists[1].displayDetails();
            displayMessage(artists[1], "Conscience is the compass of humanity.");
            artists[2].displayDetails();
            displayMessage(artists[2], "A serious work cannot be produced without great solitude.");
            std::cout << "************************ " << endl;
        }
        else if (choice == 6) {
            // Exit when the user chooses option 6
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << endl;
        }

        // Display the visitor menu again after each operation
        visitor1->displayMenu();

    } while (true); // Loop until the user chooses to exit exhibition view
}

    if (GalleryStaff* galleryStaff = dynamic_cast<GalleryStaff*>(currentUser)) {
        int choice;
        do {
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "************************ " << std::endl;
                std::cout << "The list1 of the inventory" << std::endl;
                // Define and populate the first inventory list
                set<string> inventoryList = {
                    "Painting by Picasso",
                    "Sculpture by Michelangelo",
                    "Ancient artifact from Egypt",
                    "Rare manuscript from the Renaissance",
                    "Vintage automobile from the 1920s",
                    "Contemporary installation by Banksy",
                    "Antique furniture set from the Victorian era",
                    "Photograph by Ansel Adams",
                    "Jewelry collection from a famous designer",
                    "Rare coin collection from various civilizations"
                };
                GalleryStaff staff("Admin");
                // Calling the function with a default argument with an object passed as an argument
                staff.manageInventory(inventoryList);
                std::cout << "************************ " << std::endl;
                std::cout << "The list2 of the inventory" << std::endl;
                set<string> inventoryList2 = {
                    "Soft-bristled brushes, microfiber cloths, compressed air blowers, and specialized art cleaning solutions.",
                    "Soft brushes, cotton swabs, distilled water, mild detergent solutions, and specialized cleaning tools for delicate materials.",
                    "Compressed air blowers",
                    "Microfiber cloths",
                    "Archival erasers",
                    "Cotton swabs",
                    "Distilled water",
                    "Mild detergent solutions",
                    "Kneaded erasers",
                    "Archival-quality cleaning solutions"
                };
                // Calling the function with a default argument without an object passed as an argument
                staff.manageInventory();
                std::cout << "************************ " << std::endl;
            }
            else if (choice == 2) {
                std::cout << "************************ " << std::endl;
                std::cout << "The personnel who will be involved in the opening of the exhibitions." << std::endl;
                set<string> personnelSet = { "John Smith", "Alice Johnson", "Bob Williams", "Emily Brown", "Michael Jones", "Sarah Francis", "David Davis", "Emma Stone", "James Bond", "Olivia Colman" };
                GalleryStaff staff("Admin");
                staff.personnels(personnelSet);
                std::cout << "************************ " << std::endl;
            }
            else if (choice == 3) {
                // Exit loop if choice is 3
                break;
            }
            else {
                std::cout << "Invalid choice." << std::endl;
                // Clear input buffer
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // Display the gallery staff menu again after each operation
            galleryStaff->displayMenu();

        } while (true);
    }

    // It's deallocating the memory previously allocated for the object pointed to by the pointer variable currentUser
    // Cleanup
    delete currentUser;
    return 0;
}