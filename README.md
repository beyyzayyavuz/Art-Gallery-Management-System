# Art Gallery Management System

[![CI](https://github.com/beyyzayyavuz/Art-Gallery-Management-System/actions/workflows/ci.yml/badge.svg)](https://github.com/beyyzayyavuz/Art-Gallery-Management-System/actions/workflows/ci.yml)
![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Build](https://img.shields.io/badge/build-CMake-informational.svg)

A console-based art gallery management application written in modern C++ (C++17).
It models a gallery with role-based access and demonstrates core object-oriented
programming concepts — inheritance, composition, polymorphism, function
overloading, friend functions, static members — alongside a clean data layer,
file persistence, input validation, and automated unit tests run in CI.

## Features

The program opens with a login screen offering three roles:

- **Visitor** — browse current exhibitions, search paintings, view available
  paintings with sample discounts, see newly added paintings, and read artist
  details.
- **Gallery Staff** *(password protected)* — view inventory lists and the
  personnel scheduled for exhibition openings.
- **Admin** *(password protected)* — add and remove paintings from the featured
  exhibition, persisted to `paintings.txt`.

Additional engineering touches:

- **Data layer** — a `Gallery` class owns the catalog of artists, exhibitions,
  and paintings, and loads/saves it to pipe-delimited CSV files. No hardcoded
  data lives in `main`.
- **Robust input** — invalid menu input is rejected and re-prompted instead of
  throwing the program into an infinite loop.
- **Coloured console output** via a small `Console` utility namespace.
- **Passwords** are read from the `GALLERY_ADMIN_PASSWORD` /
  `GALLERY_STAFF_PASSWORD` environment variables, with demo defaults as a
  fallback (no real credentials in source).

## Architecture

The class model favours composition over deep inheritance:

- `user` — abstract base for all roles (pure virtual `displayMenu()`, virtual
  destructor).
- `Admin`, `GalleryStaff`, `Visitor1` — concrete roles deriving from `user`.
- `Artist` — a standalone entity.
- `Exhibition` — **has an** `Artist` (composition) and a list of paintings.
- `Painting` — a standalone entity linked to an exhibition by name.
- `Gallery` — aggregate root owning the catalog and its persistence.

See `diagram.png` (UML class diagram) and the editable source `diagram.puml` in
`ArtGalleryManagement.updatedagain/ArtGalleryManagement/`.

## Building and running

### With CMake (cross-platform, recommended)

```bash
cd "ArtGalleryManagement.updatedagain/ArtGalleryManagement/ArtGalleryManagement"
cmake -B build
cmake --build build
./build/ArtGalleryManagement      # Windows: build\Debug\ArtGalleryManagement.exe
```

### Directly with a compiler

```bash
cd "ArtGalleryManagement.updatedagain/ArtGalleryManagement/ArtGalleryManagement"
g++ -std=c++17 *.cpp -o ArtGalleryManagement   # or clang++ on macOS
./ArtGalleryManagement
```

### With Visual Studio

Open `ArtGalleryManagement.updatedagain/ArtGalleryManagement/ArtGalleryManagement.sln`
and press F5.

## Tests

Unit tests use a tiny, dependency-free harness (`tests/simpletest.h`) and run on
every push via GitHub Actions.

```bash
cd "ArtGalleryManagement.updatedagain/ArtGalleryManagement/ArtGalleryManagement"
cmake -B build && cmake --build build
ctest --test-dir build --output-on-failure
```

## Project layout

```
ArtGalleryManagement/ArtGalleryManagement/
├── ArtGalleryManagement.cpp   # Entry point and menu flow
├── Gallery.{h,cpp}            # Data layer + CSV persistence
├── Console.{h,cpp}            # Input validation + coloured output
├── user / Admin / GalleryStaff / Visitor1   # Role hierarchy
├── Artist / Exhibition / Painting           # Domain model
├── tests/                     # Unit tests
├── CMakeLists.txt
├── diagram.png / diagram.puml # UML class diagram
```

## Notes

- C++17. Header files are kept free of `using namespace std;`.
- Build artifacts and generated runtime data are excluded via `.gitignore`.
