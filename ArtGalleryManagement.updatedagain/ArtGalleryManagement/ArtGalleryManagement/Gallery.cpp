#include "Gallery.h"
#include <fstream>
#include <sstream>

namespace {
    // Split a line on '|' into fields.
    std::vector<std::string> splitFields(const std::string& line, char delim = '|') {
        std::vector<std::string> fields;
        std::stringstream ss(line);
        std::string field;
        while (std::getline(ss, field, delim)) {
            fields.push_back(field);
        }
        return fields;
    }
}

Gallery::Gallery()
    : featured("Vibrant Perspectives", "May 15, 2024", "August 31, 2024", "Art Garden",
        "Paul Cezanne", "January 19, 1839", "French") {
    seedDefaults();
}

void Gallery::seedDefaults() {
    artists = {
        Artist("Leonardo da Vinci", "April 15, 1452", "Italian"),
        Artist("Vincent van Gogh", "March 30, 1853", "Dutch"),
        Artist("Pablo Picasso", "October 25, 1881", "Spanish")
    };

    exhibitions = {
        Exhibition("Renaissance Rediscovered", "May 5, 2024", "June 28, 2024", "Art Museum",
            "Leonardo da Vinci", "April 15, 1452", "Italian"),
        Exhibition("Impressionist Masterpieces", "January 1, 2024", "December 31, 2024", "Art Gallery",
            "Vincent van Gogh", "March 30, 1853", "Dutch"),
        Exhibition("Abstract Expressionism", "April 5, 2024", "May 30, 2024", "Modern Art Center",
            "Pablo Picasso", "October 25, 1881", "Spanish")
    };

    paintings = {
        Painting("Renaissance Rediscovered", "Mona Lisa", 1503, "1000000"),
        Painting("Impressionist Masterpieces", "The Starry Night", 1889, "5000000"),
        Painting("Abstract Expressionism", "Guernica", 1937, "20000000")
    };
}

bool Gallery::loadFromFiles() {
    bool loadedAny = false;

    std::ifstream af(artistsFile);
    if (af.is_open()) {
        std::vector<Artist> loaded;
        std::string line;
        while (std::getline(af, line)) {
            if (line.empty()) continue;
            auto f = splitFields(line);
            if (f.size() == 3) loaded.emplace_back(f[0], f[1], f[2]);
        }
        if (!loaded.empty()) { artists = loaded; loadedAny = true; }
    }

    std::ifstream ef(exhibitionsFile);
    if (ef.is_open()) {
        std::vector<Exhibition> loaded;
        std::string line;
        while (std::getline(ef, line)) {
            if (line.empty()) continue;
            auto f = splitFields(line);
            if (f.size() == 7) loaded.emplace_back(f[0], f[1], f[2], f[3], f[4], f[5], f[6]);
        }
        if (!loaded.empty()) { exhibitions = loaded; loadedAny = true; }
    }

    std::ifstream pf(paintingsFile);
    if (pf.is_open()) {
        std::vector<Painting> loaded;
        std::string line;
        while (std::getline(pf, line)) {
            if (line.empty()) continue;
            auto f = splitFields(line);
            if (f.size() == 4) {
                int year = 0;
                try { year = std::stoi(f[2]); } catch (...) { year = 0; }
                loaded.emplace_back(f[0], f[1], year, f[3]);
            }
        }
        if (!loaded.empty()) { paintings = loaded; loadedAny = true; }
    }

    return loadedAny;
}

void Gallery::saveToFiles() const {
    std::ofstream af(artistsFile);
    for (const Artist& a : artists) {
        af << a.getName() << '|' << a.getDateOfBirth() << '|' << a.getNationality() << '\n';
    }

    std::ofstream ef(exhibitionsFile);
    for (const Exhibition& e : exhibitions) {
        const Artist& a = e.getArtist();
        ef << e.getExhibitionName() << '|' << e.getStartDate() << '|' << e.getEndDate() << '|'
            << e.getLocation() << '|' << a.getName() << '|' << a.getDateOfBirth() << '|'
            << a.getNationality() << '\n';
    }

    std::ofstream pf(paintingsFile);
    for (const Painting& p : paintings) {
        pf << p.getExhibitionName() << '|' << p.getTitle() << '|' << p.getYearProduced() << '|'
            << p.getPrice() << '\n';
    }
}

void Gallery::addPaintingToCatalog(const Painting& painting) {
    paintings.push_back(painting);
}
