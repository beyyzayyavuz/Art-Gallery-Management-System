#include "simpletest.h"
#include "../Artist.h"
#include "../Exhibition.h"
#include "../Painting.h"
#include "../Gallery.h"
#include <string>

int main() {
    // --- Artist ---
    Artist a("Frida Kahlo", "July 6, 1907", "Mexican");
    CHECK_EQ(a.getName(), std::string("Frida Kahlo"));
    a.setNationality("Mexican-American");
    CHECK_EQ(a.getNationality(), std::string("Mexican-American"));

    // --- Painting: getters and overloaded setters ---
    Painting p("Impressionist Masterpieces", "Sunflowers", 1888, "100");
    CHECK_EQ(p.getTitle(), std::string("Sunflowers"));
    CHECK_EQ(p.getYearProduced(), 1888);
    CHECK_EQ(p.getExhibitionName(), std::string("Impressionist Masterpieces"));

    p.setPrice(0.10); // 10% discount: 100 -> 90.x
    CHECK(p.getPrice().rfind("90", 0) == 0);

    p.setPrice(std::string("250")); // string overload
    CHECK_EQ(p.getPrice(), std::string("250"));

    // Non-numeric price must not crash and must stay unchanged.
    Painting q("Expo", "Untitled", 2000, "NA");
    q.setPrice(0.5);
    CHECK_EQ(q.getPrice(), std::string("NA"));

    // --- Exhibition: composition + add/remove ---
    Exhibition e("Modern", "2024", "2024", "Hall", "Pablo Picasso", "1881", "Spanish");
    CHECK_EQ(e.getArtist().getName(), std::string("Pablo Picasso"));
    e.addPainting("Guernica");
    CHECK_EQ(e.getPaintings().size(), static_cast<size_t>(1));
    e.addPainting("Guernica"); // duplicate ignored
    CHECK_EQ(e.getPaintings().size(), static_cast<size_t>(1));
    CHECK(e.removePainting("Guernica"));
    CHECK(!e.removePainting("Does Not Exist"));

    // --- Gallery: seed data + save/load round trip ---
    Gallery g;
    CHECK_EQ(g.getArtists().size(), static_cast<size_t>(3));
    CHECK_EQ(g.getExhibitions().size(), static_cast<size_t>(3));
    CHECK_EQ(g.getPaintings().size(), static_cast<size_t>(3));

    g.saveToFiles();
    Gallery g2;
    bool loaded = g2.loadFromFiles();
    CHECK(loaded);
    CHECK_EQ(g2.getPaintings().size(), static_cast<size_t>(3));
    CHECK_EQ(g2.getExhibitions()[0].getArtist().getName(),
        g.getExhibitions()[0].getArtist().getName());

    return TEST_SUMMARY();
}
