#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include "Artist.h"
#include "user.h"
#include "Painting.h"
#include "Exhibition.h"
#include "Visitor1.h"
#include "Admin.h"
#include "GalleryStaff.h"
#include "Gallery.h"
#include "Console.h"

using namespace std;

// Passwords are read from environment variables when present, otherwise fall
// back to the demo defaults. Storing real credentials in source is avoided.
static string staffPassword() {
    const char* p = std::getenv("GALLERY_STAFF_PASSWORD");
    return p ? p : "4321";
}
static string adminPassword() {
    const char* p = std::getenv("GALLERY_ADMIN_PASSWORD");
    return p ? p : "1234";
}

// Returns the logged-in user, or nullptr on failure.
unique_ptr<user> login() {
    Console::title("Art Gallery Management System");
    cout << "Log in:\n";
    cout << "  1) Visitor\n";
    cout << "  2) Gallery Staff\n";
    cout << "  3) Admin\n";

    int choice = Console::readInt("Enter your choice: ");

    if (choice == 1) {
        return make_unique<Visitor1>();
    }
    else if (choice == 2) {
        string password = Console::readLine("Enter password: ");
        if (password == staffPassword()) {
            return make_unique<GalleryStaff>("Staff");
        }
        Console::error("Incorrect password. Access denied.");
        return nullptr;
    }
    else if (choice == 3) {
        string password = Console::readLine("Enter password: ");
        if (password == adminPassword()) {
            return make_unique<Admin>("Admin");
        }
        Console::error("Incorrect password. Access denied.");
        return nullptr;
    }
    Console::error("Invalid choice. Please try again.");
    return nullptr;
}

// Saves the titles of an exhibition's paintings to a file (one per line).
void savePaintingsToFile(const Exhibition& exhibition, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const string& painting : exhibition.getPaintings()) {
            file << painting << '\n';
        }
        Console::success("Paintings saved to file successfully!");
    }
    else {
        Console::error("Unable to open file for saving paintings.");
    }
}

void runAdmin(Admin* admin, Gallery& gallery) {
    Exhibition& exhibition = gallery.getFeaturedExhibition();
    int choice;
    do {
        choice = Console::readInt("Enter your choice: ");
        if (choice == 1) {
            string paintingTitle = Console::readLine("Enter the title of the painting to add: ");
            const auto& current = exhibition.getPaintings();
            if (find(current.begin(), current.end(), paintingTitle) == current.end()) {
                exhibition.addPainting(paintingTitle);
                savePaintingsToFile(exhibition, "paintings.txt");
                exhibition.displayDetails();
                Console::success("Painting added successfully!");
            }
            else {
                Console::error("Painting already exists.");
            }
        }
        else if (choice == 2) {
            string paintingToRemove = Console::readLine("Enter the title of the painting to remove: ");
            if (exhibition.removePainting(paintingToRemove)) {
                savePaintingsToFile(exhibition, "paintings.txt");
                exhibition.displayDetails();
                Console::success("Painting removed successfully!");
            }
            else {
                Console::error("Painting not found.");
            }
        }
        else if (choice == 3) {
            break;
        }
        else {
            Console::error("Invalid choice.");
        }
        admin->displayMenu();
    } while (true);
}

void runVisitor(Visitor1* visitor, Gallery& gallery) {
    auto& exhibitions = gallery.getExhibitions();
    int choice;
    do {
        choice = Console::readInt("Enter your choice: ");
        if (choice == 1) {
            visitor->viewExhibitionMenu(exhibitions);
            int sel = Console::readInt("Enter your choice: ");
            if (sel >= 1 && sel <= static_cast<int>(exhibitions.size())) {
                Console::separator();
                exhibitions[sel - 1].clearPaintings();
                // paintings[i] is aligned 1:1 with exhibitions[i] in the seed data.
                if (sel - 1 < static_cast<int>(gallery.getPaintings().size())) {
                    exhibitions[sel - 1].addPainting(gallery.getPaintings()[sel - 1].getTitle());
                }
                visitor->viewExhibitionDetails(exhibitions[sel - 1]);
                Console::separator();
            }
            else if (sel == static_cast<int>(exhibitions.size()) + 1) {
                // Return to main menu
            }
            else {
                Console::error("Invalid choice. Please try again.");
            }
        }
        else if (choice == 2) {
            Console::separator();
            string searchQuery = Console::readLine("Enter the search query: ");
            visitor->searchPaintings(searchQuery, "paintings.txt");
            Console::separator();
        }
        else if (choice == 3) {
            Console::title("Available paintings");
            // Work on a copy so discount display does not mutate the catalog.
            vector<Painting> paintings = gallery.getPaintings();
            for (const Painting& painting : paintings) {
                Painting::displayPaintingDetails(painting);
                Console::separator();
            }
            Console::info("DETAILED PAINTING PRICES (with sample discounts)");
            const double rates[] = { 0.10, 0.02, 0.30 };
            for (size_t i = 0; i < paintings.size(); ++i) {
                cout << "The original price of " << paintings[i].getTitle()
                    << ": " << paintings[i].getPrice() << '\n';
                paintings[i].setPrice(rates[i % 3]);
                cout << "The discounted price of " << paintings[i].getTitle()
                    << ": " << paintings[i].getPrice() << '\n';
                Console::separator();
            }
        }
        else if (choice == 4) {
            Console::title("Newly added paintings");
            ifstream file("paintings.txt");
            if (file.is_open()) {
                string painting;
                while (getline(file, painting)) {
                    cout << painting << '\n';
                }
            }
            else {
                Console::error("Unable to open paintings.txt file.");
            }
        }
        else if (choice == 5) {
            Console::title("Artists with exhibitions in this gallery");
            const auto& artists = gallery.getArtists();
            const char* quotes[] = {
                "Love shines brightest in the darkest places.",
                "Conscience is the compass of humanity.",
                "A serious work cannot be produced without great solitude."
            };
            for (size_t i = 0; i < artists.size(); ++i) {
                artists[i].displayDetails();
                displayMessage(artists[i], quotes[i % 3]);
                Console::separator();
            }
        }
        else if (choice == 6) {
            break;
        }
        else {
            Console::error("Invalid choice. Please try again.");
        }
        visitor->displayMenu();
    } while (true);
}

void runGalleryStaff(GalleryStaff* galleryStaff) {
    int choice;
    do {
        choice = Console::readInt("Enter your choice: ");
        if (choice == 1) {
            Console::title("Inventory");
            set<string> inventoryList = {
                "Painting by Picasso", "Sculpture by Michelangelo", "Ancient artifact from Egypt",
                "Rare manuscript from the Renaissance", "Vintage automobile from the 1920s",
                "Contemporary installation by Banksy", "Antique furniture set from the Victorian era",
                "Photograph by Ansel Adams", "Jewelry collection from a famous designer",
                "Rare coin collection from various civilizations"
            };
            galleryStaff->manageInventory(inventoryList);
        }
        else if (choice == 2) {
            Console::title("Personnel for exhibition openings");
            set<string> personnelSet = {
                "John Smith", "Alice Johnson", "Bob Williams", "Emily Brown", "Michael Jones",
                "Sarah Francis", "David Davis", "Emma Stone", "James Bond", "Olivia Colman"
            };
            galleryStaff->personnels(personnelSet);
        }
        else if (choice == 3) {
            break;
        }
        else {
            Console::error("Invalid choice.");
        }
        galleryStaff->displayMenu();
    } while (true);
}

int main() {
    Gallery gallery;
    gallery.loadFromFiles(); // Override seed data if CSV files exist

    unique_ptr<user> currentUser;
    while (!currentUser) {
        currentUser = login();
    }

    currentUser->displayMenu();

    if (Admin* admin = dynamic_cast<Admin*>(currentUser.get())) {
        runAdmin(admin, gallery);
    }
    else if (Visitor1* visitor = dynamic_cast<Visitor1*>(currentUser.get())) {
        runVisitor(visitor, gallery);
    }
    else if (GalleryStaff* staff = dynamic_cast<GalleryStaff*>(currentUser.get())) {
        runGalleryStaff(staff);
    }

    gallery.saveToFiles(); // Persist the catalog on exit
    Console::success("Goodbye!");
    return 0;
}
