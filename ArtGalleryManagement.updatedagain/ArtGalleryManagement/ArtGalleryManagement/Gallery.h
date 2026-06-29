#ifndef GALLERY_H
#define GALLERY_H

#include "Artist.h"
#include "Exhibition.h"
#include "Painting.h"
#include <vector>
#include <string>

// Gallery is the data layer / aggregate root of the application.
// It owns the catalog of artists, exhibitions and paintings, and is
// responsible for loading and saving that catalog to disk. This keeps
// main() free of hardcoded data and persistence logic.
class Gallery {
private:
    std::vector<Artist> artists;
    std::vector<Exhibition> exhibitions;
    std::vector<Painting> paintings;
    Exhibition featured; // The exhibition the Admin role edits at runtime

    // File names (pipe-delimited so values may contain commas, e.g. dates).
    std::string artistsFile = "artists.csv";
    std::string exhibitionsFile = "exhibitions.csv";
    std::string paintingsFile = "paintings.csv";

public:
    Gallery();

    // Populate with the built-in default catalog.
    void seedDefaults();

    // Load the catalog from CSV files. Returns true if at least one file was read.
    bool loadFromFiles();

    // Persist the current catalog to CSV files.
    void saveToFiles() const;

    // Accessors
    const std::vector<Artist>& getArtists() const { return artists; }
    const std::vector<Exhibition>& getExhibitions() const { return exhibitions; }
    std::vector<Exhibition>& getExhibitions() { return exhibitions; }
    const std::vector<Painting>& getPaintings() const { return paintings; }
    Exhibition& getFeaturedExhibition() { return featured; }

    // Catalog mutation
    void addPaintingToCatalog(const Painting& painting);
};

#endif /* GALLERY_H */
