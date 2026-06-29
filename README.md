# Art Gallery Management System

A console-based art gallery management application written in modern C++. It
demonstrates core object-oriented programming concepts — inheritance,
composition, polymorphism, function overloading, operator usage, friend
functions, static members, and file I/O — through a role-based gallery system.

## Features

The program starts with a login screen offering three roles:

- **Visitor** – browse current exhibitions, search paintings, view available
  paintings with discounted prices, see newly added paintings, and view artist
  details.
- **Gallery Staff** *(password protected)* – view inventory lists and the
  personnel scheduled for exhibition openings.
- **Admin** *(password protected)* – add and remove paintings from an
  exhibition, with changes persisted to `paintings.txt`.

## Architecture

The class model favours composition over deep inheritance:

- `user` — abstract base class for all roles (pure virtual `displayMenu()`,
  virtual destructor).
- `Admin`, `GalleryStaff`, `Visitor1` — concrete roles deriving from `user`.
- `Artist` — a standalone entity (name, date of birth, nationality).
- `Exhibition` — **has an** `Artist` (composition) and a collection of paintings.
- `Painting` — a standalone entity associated with an exhibition by name.

Polymorphism is used via `user*` pointers and `dynamic_cast`; function
overloading is shown in `Painting::setPrice`; a friend function
(`displayMessage`) and static member functions are also demonstrated.

## Building

### With CMake (cross-platform)

```bash
cd "ArtGalleryManagement.updatedagain/ArtGalleryManagement/ArtGalleryManagement"
cmake -B build
cmake --build build
./build/ArtGalleryManagement      # Windows: build\Debug\ArtGalleryManagement.exe
```

### With Visual Studio

Open `ArtGalleryManagement.updatedagain/ArtGalleryManagement/ArtGalleryManagement.sln`
and build/run (F5).

## Notes

- C++17 standard.
- Header files are kept free of `using namespace std;`.
- Build artifacts (`.vs/`, `build/`, object files) are excluded via `.gitignore`.
