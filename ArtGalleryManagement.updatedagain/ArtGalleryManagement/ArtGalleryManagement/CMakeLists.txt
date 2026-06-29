cmake_minimum_required(VERSION 3.10)
project(ArtGalleryManagement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ArtGalleryManagement
    ArtGalleryManagement.cpp
    Artist.cpp
    Exhibition.cpp
    Painting.cpp
    Visitor1.cpp
    Admin.cpp
    GalleryStaff.cpp
    user.cpp
)
